#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double *A, *B, *C;
long N, K, M, numOfThreads;

int main(int argc, char *argv[])
{
    long printResults;
    char *EndPtr;
    struct timeval start, end;
    double elapsed_time;

    if (argc != 6)
    {
        printf("USAGE: %s <N> <K> <M> <PRINT RESULTS> <NUMBER OF THREADS>\n", argv[0]);
        exit(1);
    }

    N = strtol(argv[1], &EndPtr, 10);
    if (*EndPtr != '\0' || N < 1)
    {
        printf("Invalid number for N provided.\n");
        exit(1);
    }

    K = strtol(argv[2], &EndPtr, 10);
    if (*EndPtr != '\0' || K < 1)
    {
        printf("Invalid number for K provided.\n");
        exit(1);
    }

    M = strtol(argv[3], &EndPtr, 10);
    if (*EndPtr != '\0' || M < 1)
    {
        printf("Invalid number for M provided.\n");
        exit(1);
    }

    printResults = strtol(argv[4], &EndPtr, 10);
    if (*EndPtr != '\0')
    {
        printf("Invalid number for printResults provided.\n");
        exit(1);
    }

    numOfThreads = strtol(argv[5], &EndPtr, 10);
    if (*EndPtr != '\0' || numOfThreads < 1)
    {
        printf("Invalid number of threads provided.\n");
        exit(1);
    }

    /*
     * Allocate memory for input and output arrays.
     * All elementrs of the output array are initialized to 0.
     */
    A = (double *)malloc(N * K * sizeof(double));
    if (A == NULL)
    {
        printf("Could not allocate memory for array A.\n");
        exit(2);
    }

    B = (double *)malloc(K * M * sizeof(double));
    if (B == NULL)
    {
        printf("Could not allocate memory for array B.\n");
        free(A);
        exit(2);
    }

    C = (double *)calloc(N * M, sizeof(double));
    if (C == NULL)
    {
        printf("Could not allocate memory for array C.\n");
        free(A);
        free(B);
        exit(2);
    }

    printf("Starting initialization of array A.\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            A[i * K + j] = 3.0 * drand48();
    printf("Finished initialization of array A.\n");

    printf("Starting initialization of array B.\n");
    for (int i = 0; i < K; i++)
        for (int j = 0; j < M; j++)
            B[i * M + j] = 3.0 * drand48();
    printf("Finished initialization of array B.\n");

    /*
     * Matrix-Matrix multiplication
     */
    gettimeofday(&start, NULL);

    #pragma omp parallel {
        #pragma omp for
        for (int i = 0; i < N; i++)
            for (int k = 0; k < K; k++)
                for (int j = 0; j < M; j++)
                    C[i * M + j] += A[i * K + k] * B[k * M + j];
    }

    gettimeofday(&end, NULL);

    elapsed_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Time for multiplication: %f sec\n", elapsed_time);

    if (printResults != 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                printf("%25.16f", C[i * M + j]);
            }
            printf("\n");
        }
    }

    return (0);
}