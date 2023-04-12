#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double	*A, *B, *C;
long	N, K, M, numOfThreads;

int main(int argc, char *argv[])
{
	long		i, j, k, printResults;
	char		*EndPtr;
	struct timeval	start, end;

	if (argc != 6) {
		printf("USAGE: %s <N> <K> <M> <PRINT RESULTS> <NUMBER OF THREADS>\n", argv[0]);
		exit(1);
	}

	N = strtol(argv[1], &EndPtr, 10);
	if (*EndPtr != '\0' || N < 1) {
		printf("Invalid number for N provided.\n");
		exit(1);
	}

	K = strtol(argv[2], &EndPtr, 10);
	if (*EndPtr != '\0' || K < 1) {
		printf("Invalid number for K provided.\n");
		exit(1);
	}

	M = strtol(argv[3], &EndPtr, 10);
	if (*EndPtr != '\0' || M < 1) {
		printf("Invalid number for M provided.\n");
		exit(1);
	}

	printResults = strtol(argv[4], &EndPtr, 10);
	if (*EndPtr != '\0') {
		printf("Invalid number for printResults provided.\n");
		exit(1);
	}

	numOfThreads = strtol(argv[5], &EndPtr, 10);
	if (*EndPtr != '\0' || numOfThreads < 1) {
		printf("Invalid number of threads provided.\n");
		exit(1);
	}

	/*
	 * Allocate memory for input and output arrays.
	 * All elementrs of the output array are initialized to 0.
	 */
	A = (double *)malloc(N * K * sizeof(double));
	if (A == NULL) {
		printf("Could not allocate memory for array A.\n");
		exit(2);
	}

	B = (double *)malloc(K * M * sizeof(double));
	if (B == NULL) {
		printf("Could not allocate memory for array B.\n");
		exit(2);
	}

	C = (double *)calloc(N * M, sizeof(double));
	if (C == NULL) {
		printf("Could not allocate memory for array C.\n");
		exit(2);
	}

	printf("Starting initialization of array A.\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < K; j++) {
			A[i * K + j] = 3.0 * drand48();
		}
	}
	printf("Finished initialization of array A.\n");

	printf("Starting initialization of array B.\n");
	for (i = 0; i < K; i++) {
		for (j = 0; j < M; j++) {
			B[i * M + j] = 3.0 * drand48();
		}
	}
	printf("Finished initialization of array B.\n");


	/*
	 * Matrix-Matrix multiplication
	 */
	gettimeofday(&start, NULL);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (k = 0; k < K; k++) {
				C[i * M + j] += A[i * K + k] * B[k * M + j];
			}
		}
	}

	gettimeofday(&end, NULL);

	printf("Time for multiplication: %f sec\n", (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0);

	if (printResults != 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				printf("%25.16f", C[i * M + j]);
			}
			printf("\n");
		}
	}

	return(0);
}

