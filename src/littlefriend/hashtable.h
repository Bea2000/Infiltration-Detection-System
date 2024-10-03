#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct hashitem_t {
    int i;
    int j;
    int n;
    struct hashitem_t *next;
} HashItem;

int hash_function(int value, int combinations);

void insert_or_update(HashItem **table, int n, int i, int j, int index);

int fetch_value(HashItem **table, int key, int sub_n, int n, int **sub_matrix, int **matrix);

int find_submatrix(HashItem *item,int n, int sub_n, int **matrix, int **sub_matrix);

void create_hashes(int n,int **matrix, int combinations, HashItem **table);

void hash_matrix(int i,int j,int n, int max_dim, int **matrix, int combinations, HashItem **table);

int calculate_combinations(int n);

int hash_submatrix(int sub_n, int n, int **sub_matrix, int **matrix, int combinations, HashItem **table);