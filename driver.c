#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matmul.c"

void read_matrix(const char *filename, int ***matrix, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", rows);
    fscanf(file, "%d", cols);

    *matrix = malloc((*rows) * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        (*matrix)[i] = malloc((*cols) * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &((*matrix)[i][j]));
        }
    }

    fclose(file);
}

int compare_matrices(int **A, int **B, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] != B[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {

    int m1, n1, m2, n2, m3, n3;
    int **A, **B, **C, **Result;

    char filepath[256];

    sprintf(filepath, "Unit_test/unit_%s/A.txt", argv[1]);
    read_matrix(filepath, &A, &m1, &n1);

    sprintf(filepath, "Unit_test/unit_%s/B.txt", argv[1]);
    read_matrix(filepath, &B, &m2, &n2);

    // Yet to add dimension checks for negative test cases

    sprintf(filepath, "Unit_test/unit_%s/C.txt", argv[1]);
    int status;

    read_matrix(filepath, &C, &m3, &n3);

    // yet to add mismatches between dimensions of matrices

    Result = calloc(m1, sizeof(int *));
    for (int i = 0; i < m1; i++) {
        Result[i] = calloc(n2, sizeof(int));
    }

    char *variation = argv[2];
    clock_t start_time;
    clock_t end_time;
    double time_taken;

    // Call the appropriate matrix multiplication function based on the defined variation
    if (strcmp(variation, "ijk") == 0) {
        start_time = clock();
        matrix_multiply_ijk(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    } else if (strcmp(variation, "ikj") == 0) {
        start_time = clock();
        matrix_multiply_ikj(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    } else if (strcmp(variation, "jik") == 0) {
        start_time = clock();
        matrix_multiply_jik(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    } else if (strcmp(variation, "jki") == 0) {
        start_time = clock();
        matrix_multiply_jki(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    } else if (strcmp(variation, "kij") == 0) {
        start_time = clock();
        matrix_multiply_kij(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    } else if (strcmp(variation, "kji") == 0) {
        start_time = clock();
        matrix_multiply_kji(A, B, Result, m1, n2, m2);
        end_time = clock(); 
    }
    time_taken = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC * 1000;
    if (compare_matrices(Result, C, m1, n2)) {
        printf("Passed!,  %.3f ms\n", time_taken);
    } else {
        printf("Failed!, %.3f ms\n", time_taken);
    }

    for (int i = 0; i < m1; i++) free(A[i]);
    for (int i = 0; i < m2; i++) free(B[i]);
    for (int i = 0; i < m3; i++) free(C[i]);
    for (int i = 0; i < m1; i++) free(Result[i]);
    free(A);
    free(B);
    free(C);
    free(Result);

    return 0;
}
