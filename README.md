# Parallel Computing Project (2023) - Performance Optimization Using POSIX Threads and OpenMP

## Project Overview

This repository contains the final project for the "Parallel Computing" course, conducted in the 6th semester of the 2022-2023 academic year at the University of Piraeus, Department of Informatics. The project focuses on performance optimization of matrix operations using parallel computing techniques, particularly **POSIX Threads** and **OpenMP**, exploring the execution times across various matrix sizes and thread counts.

The objective is to implement parallel solutions, compare them with sequential execution, and analyze the impact of optimizations on performance. The system measures execution times under different optimization levels and scheduling policies using matrix multiplications.

## Course Information

- **Institution:** [University of Piraeus](https://www.unipi.gr/en/)
- **Department:** [Department of Informatics](https://cs.unipi.gr/en/)
- **Course:** Parallel Computing (2022-2023)
- **Semester:** 6th

## Technologies Used

- **C (POSIX Threads, OpenMP)**
- **GCC Compiler** for code compilation and optimizations

## Optimization Techniques Explored

The project implements and benchmarks different optimization techniques using matrix multiplications under several conditions:

1. **Sequential Execution:** Without any parallelization.
2. **Parallel Execution with POSIX Threads:** Using a varying number of threads.
3. **Parallel Execution with OpenMP:** Comparing dynamic, guided, and static scheduling policies.
    - **Dynamic Scheduling:** Allocates chunks of iterations dynamically as threads finish their assigned chunks.
    - **Guided Scheduling:** Similar to dynamic but reduces the chunk size over time.
    - **Static Scheduling:** Pre-assigns equal-sized chunks of iterations to each thread.
4. Optimizations:
    - **GCC -O0:** No optimization
    - **GCC -O3:** Full optimization with loop vectorization

## Dataset Details

The matrices used in the computations have varying sizes:

- **N = 2000, 100, 4000** for smaller-scale tests
- **N = 8000, K = 200, M = 40000** for large-scale tests

Different thread counts and chunk sizes were used to study their impact on performance:

- Chunk sizes of **4** and **100** for scheduling policies in OpenMP.

## Setup Instructions

1. **Linux Requirement**

    It is necessary to use a Linux-based system for this project. You can either install a Linux distribution (e.g., **Ubuntu 20.04.2 LTS**) directly on your machine or run it in a virtual machine using software like **VirtualBox** or **VMware Player**. Ensure that the system supports multiple CPU cores, as parallel programs will be executed.

2. **Compilation and Execution**

    - **Compiling the Sequential Program**

        To compile the provided sequential matrix multiplication program:

        ```bash
        gcc -O3 -Wall -Wextra -o mm mm.c
        ```

        This creates an executable named `mm`. You can run the program with:

        ```bash
        ./mm <N> <K> <M> <print_results> <num_threads>
        ```

        Where:

        - `<N>`, `<K>`, `<M>` are the dimensions of the matrices.
        - `<print_results>`: Use a non-zero value to print the results or 0 to avoid printing.
        - `<num_threads>`: Although not used in the sequential version, it should be provided for compatibility with parallel versions.

        For example

        ```bash
        ./mm 100 400 600 0 1
        ```

    - **Compiling the Parallel Program with POSIX Threads**
  
        To compile your parallel program using **POSIX Threads**:

        ```bash
        gcc -O3 -pthread -Wall -Wextra -o mm_pthreads mm_pthreads.c
        ```

        This creates an executable named `mm_pthreads`. Run the program with:

        ```bash
        ./mm_pthreads <N> <K> <M> <print_results> <num_threads>
        ```

    - **Compiling the Parallel Program with OpenMP**
  
       To compile the program using **OpenMP**:

       ```bash
       gcc -O3 -fopenmp -Wall -Wextra -o mm_omp mm_omp.c
       ```

       This creates an executable named `mm_omp`. Set the number of threads for OpenMP using:

       ```basj
       export OMP_NUM_THREADS=<num_threads>
       ```

       Then run the program with:

       ```bash
       ./mm_omp <N> <K> <M> <print_results> <num_threads>
       ```

3. **Testing and Execution**

    Test your programs with the following matrix sizes:

    - **Square Matrices**: N = K = M = 2000
    - **Tall A and Wide B**: N = 100, K = 4000, M = 20000
    - **Wide A and Tall B**: N = 4000, K = 100, M = 20000
  
    For more accurate results, test with larger matrices that result in execution times greater than 1 minute for the sequential version. You can use smaller matrices during development for quick testing.

## Project Documentation

For detailed information about the architecture, code structure, and functionalities, refer to the `Project-documentation.pdf` located in the `/docs` directory. This document covers all aspects of the MVC pattern, the database schema, and role-based access control used in the application.

## Contributors

<table>
      <td align="center"><a href="https://github.com/dimitrisstyl7"><img src="https://avatars.githubusercontent.com/u/75742419?v=4" width="100px;" alt="Apostolis Siampanis"/><br /><sub><b>Dimitris Stylianou</b></sub></a><br /></td>
      <td align="center"><a href="https://github.com/ApostolisSiampanis"><img src="https://avatars.githubusercontent.com/u/75365398?v=4" width="100px;" alt="Apostolis Siampanis"/><br /><sub><b>Apostolis Siampanis</b></sub></a><br /></td>
      <td align="center"><a href="https://github.com/kostas96674"><img src="https://avatars.githubusercontent.com/u/79859276?v=4" width="100px;" alt="Apostolis Siampanis"/><br /><sub><b>Konstantinos Loizidis</b></sub></a><br /></td>
</table>

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.
