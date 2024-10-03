#include "hashtable.h"

int hash_function(int value, int combinations) {
    return (value % combinations);
}

void insert_or_update(HashItem **table, int x, int i, int j, int index){
    HashItem *item = table[index];
    if(item==NULL){
        item = malloc(sizeof(HashItem));
        item->n = x;
        item->i = i;
        item->j = j;
        item->next = NULL;
        table[index] = item;
    } else{
        while(item->next != NULL){
            item = item->next;
        }
        HashItem *add = malloc(sizeof(HashItem));
        add->n = x;
        add->i = i;
        add->j = j;
        add->next = NULL;
        item->next = add;
    }
}

int fetch_value(HashItem **table, int key, int sub_n, int n, int **sub_matrix, int **matrix) {
    HashItem *item = table[key];
    while(item != NULL){
        if(item->n == sub_n){
            if(find_submatrix(item,n, sub_n, matrix, sub_matrix) == 1){
                return 1;
            }
            else{
                item = item->next;
            }
        } else{
            item = item->next;
        }
    }
    return 0;
}

int find_submatrix(HashItem *item,int n, int sub_n, int **matrix, int **sub_matrix){
    int i = item->i;
    int j = item->j;
    for(int k=0;k<sub_n;k++){
        for(int x=0; x<sub_n;x++){
            int m = matrix[k+i][x+j];
            int s = sub_matrix[k][x];
            if(m != s){
                return 0;
            }
        }
    }
    return 1;
}

int calculate_combinations(int n){
    int combinations = 0;
    for(int i = (n-1); i >= 1; i--){
        combinations += i*i;
    }
    return combinations;
}

void create_hashes(int n,int **matrix, int combinations, HashItem **table){
    for(int i=0;i<n-1;i++){ //recorremos filas
        for(int j=0;j<n-1;j++){ //recorremos columnas
            // parte en (0,0)
            int max_dim;
            if(i > j){
                max_dim = n-i;
            }else{
                max_dim = n-j;
            }
            hash_matrix(i,j, n, max_dim, matrix, combinations, table);
        }
    }
}

void hash_matrix(int i,int j,int n, int max_dim, int **matrix, int combinations, HashItem **table){
    int first_diagonal;
    int second_diagonal;
    int num;
    int hash;
    for(int x=2;x<=max_dim;x++){
        first_diagonal = 0;
        second_diagonal = 0;
        for(int k=0;k<x;k++){
            num = matrix[i+k][j+k];
            first_diagonal = first_diagonal+num;
            num = matrix[i+x-k-1][k+j];
            second_diagonal = second_diagonal + num;
        }
        hash = x*(first_diagonal+second_diagonal);
        hash = hash_function(hash,combinations);
        insert_or_update(table,x,i,j,hash);
    }
}

int hash_submatrix(int sub_n, int n, int **sub_matrix, int **matrix, int combinations, HashItem **table){
    int first_diagonal = 0;
    int second_diagonal = 0;
    int num;
    int hash;
        for(int k=0;k<sub_n;k++){
            num = sub_matrix[k][k];
            first_diagonal = first_diagonal+num;
            num = sub_matrix[sub_n-k-1][k];
            second_diagonal = second_diagonal + num;
        }
        hash = sub_n*(first_diagonal+second_diagonal);
        hash = hash_function(hash,combinations);
        int value = fetch_value(table, hash, sub_n, n, sub_matrix, matrix);
        return value;
}