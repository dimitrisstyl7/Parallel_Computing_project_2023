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
