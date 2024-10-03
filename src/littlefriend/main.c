#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void check_args(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s input querys output\n", argv[0]);
        exit(1);
    }
}

int main(int argc, char *argv[]){
    check_args(argc, argv);
    int n;
    int value;
    int i;
    int j;
    FILE* input_file = fopen(argv[1], "r");
    fscanf(input_file, "%d", &n);
    int **matrix = malloc(n * sizeof(*matrix));
    for (i = 0; i < n; i++) { 
        matrix[i]=malloc(n * sizeof(*(matrix[i])));
    }

    int combinations = calculate_combinations(n);
    HashItem **table = calloc(combinations,sizeof(HashItem*));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fscanf(input_file, "%d", &value);
            matrix[i][j] = value;
        }
    }
    fclose(input_file);
    create_hashes(n,matrix,combinations, table);
    int query_count;
    int sub_n;
    int result;
    int q;
    FILE* queries_file = fopen(argv[2], "r");
    FILE* output_file = fopen(argv[3], "w");
    fscanf(queries_file, "%d", &query_count);
    for(q=0; q<query_count; q++){
        fscanf(queries_file, "%d", &sub_n);
        int **sub_matrix = malloc(sub_n * sizeof(*sub_matrix));
        for (i = 0; i < sub_n; i++) { 
            sub_matrix[i]=malloc(sub_n * sizeof(*(sub_matrix[i])));
        }
        for(i=0;i<sub_n;i++){
            for(j=0;j<sub_n;j++){
                fscanf(queries_file, "%d", &value);
                sub_matrix[i][j] = value;
            }
        }
        result = hash_submatrix(sub_n,n,sub_matrix,matrix,combinations, table);
        fprintf(output_file,"%i\n", result);
        for(i=0; i<sub_n;i++){
            free(sub_matrix[i]);
        }
        free(sub_matrix); 
    }
    fclose(queries_file);
    fclose(output_file);
    for(i=0; i<n;i++){
        free(matrix[i]);
    }
    free(matrix);
    for(i=0;i<combinations;i++){
        HashItem *item = table[i];
        while(item != NULL){
            HashItem *tmp = item;
            item = item->next;
            free(tmp);
        }
        free(item);
    }
    free(table);

    return 0;
}