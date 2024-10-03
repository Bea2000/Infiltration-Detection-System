# Infiltration Detection System

This project was developed for the **Data Structures and Algorithms** course during the first semester of 2021 at the **Pontifical Catholic University of Chile**. It focuses on applying **hash tables** and **efficient search algorithms** to solve a challenging NP-Complete problem: detecting infiltrators in an organization by analyzing low-resolution surveillance images. The task involves handling large datasets and optimizing the search process using **incremental hashing** to ensure efficient detection of suspicious patterns.

## Problem Description

You are given:

- A grid representing the surveillance footage of your facilities.
- A set of sub-images representing the known appearances of infiltrators.
Your task is to efficiently detect whether any of these sub-images appear in the main grid, and if so, how many times. Given the computational restrictions caused by a virus in the system, brute-force approaches are not viable, and you must use **hash tables** to perform an efficient search.

## Objectives

1. **Model the problem** and solve it using efficient data structures.
2. **Analyze different hashing algorithms** and implement an **incremental hashing function** for optimal performance.
3. Apply **hash tables** to detect patterns within the main grid efficiently.
4. Ensure the program runs in a time-efficient manner, avoiding brute-force search.

## Requirements

To run the project, you need:

- A **C compiler** (e.g., `gcc`)
- **Make utility** for building the project.

The program must compile and run with the following commands:

### Compilation

```bash
make
```

This will generate an executable named littlefriend.

## Execution

The executable takes three arguments:

- `input.txt` - A file containing the main grid representing the base image.
- `querys.txt` - A file containing sub-images (queries) to be searched within the main grid.
- `output.txt` - A file where the output of the detection process will be written.

```bash
./littlefriend input.txt querys.txt output.txt
```

## Input Format

1. Main Grid (`input.txt`)

    The main grid input consists of:

    - An integer `N` representing the dimensions of the grid (N x N).
    - Followed by `N` lines, each containing `N` integers (0-255) representing the pixel values of the grid.

    *Example:*

    ```sql
    5
    0 0 1 1 245
    40 0 5 0 15
    0 10 97 0 1
    40 0 20 5 0
    40 0 0 0 0
    ```

2. Sub-images (`querys.txt`)

    The queries input contains:

    - An integer `Q` representing the number of sub-images.
    - For each query, an integer `M` representing the dimensions of the sub-image (M x M).
    - Followed by `M` lines of integers (0-255) representing the pixel values of the sub-image

    Example:

    ```sql
    2
    3
    0 0 1
    0 0 2
    0 1 2
    4
    0 0 4 0
    0 0 2 0
    0 1 2 4
    0 0 2 0
    ```

## Output Format

The output file will contain `Q` lines, where each line corresponds to one of the sub-images from `querys.txt`. Each line will contain:

`1` if the sub-image is present in the main grid.
`0` if the sub-image is not present.

Example:

```sql
1
0
1
1
```

## Hashing Requirements

The key requirement is the use of a hash table for detecting sub-images efficiently. The hash function should be designed to work incrementally, so that as the program checks different regions of the grid, it can reuse computed hash values instead of recalculating them from scratch. This is crucial for achieving the necessary efficiency.

## Example

For an input grid of size 5x5 and the following queries:

Main Grid (`input.txt`):

```sql
5
0 0 1 1 245
40 0 5 0 15
0 10 97 0 1
40 0 20 5 0
40 0 0 0 0
```

Queries (`querys.txt`):

```sql
2
3
0 0 1
0 0 2
0 1 2
4
0 0 4 0
0 0 2 0
0 1 2 4
0 0 2 0
```

Output (`output.txt`):

```sql
1
0
1
1
```

This means the first query (sub-image) was found in the main grid, but the second was not.
