#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "matmul.c"
#define MISC_ERROR 2

int is_file_empty(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    // Move to the end of the file
    fseek(file, 0, SEEK_END);
    long size = ftell(file); // Get the current position (size of the file)

    fclose(file);

    return size == 0; // Return 1 if empty, 0 if not
}

void handle_error(const char *error_message, int expected_status) {
    if (expected_status == -1) {
        printf("Passed!, , %s\n", error_message);
    } else {
        printf("Failed!, NA, %s\n", error_message);
    }
    exit(EXIT_SUCCESS);
}

void read_matrix(const char *filename, int ***matrix, int *rows, int *cols, int expected_status) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handle_error("File not found.", MISC_ERROR);
    }

    if (fscanf(file, "%d\n%d", rows, cols) != 2) {
        handle_error("Matrix dimensions are missing or invalid.", expected_status);
    }

    if (*rows <= 0 || *cols <= 0) {
        handle_error("Matrix dimensions must be positive integers.", expected_status);
    }

    *matrix = malloc((*rows) * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        (*matrix)[i] = malloc((*cols) * sizeof(int));
        for (int j = 0; j < *cols; j++) {
            if (fscanf(file, "%d", &((*matrix)[i][j])) != 1) {
                handle_error("Matrix contains missing or invalid values.", expected_status);
            }
        }
    }

    fclose(file);
}

int compare_matrices(int **matrix_1, int **matrix_2, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix_1[i][j] != matrix_2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}



int main(int argc, char *argv[]) {
    if (argc != 3) {
        handle_error("command line arguments not found", MISC_ERROR);
    }
    int A_row_size, A_col_size, B_row_size, B_col_size, C_row_size, C_col_size;
    int **A, **B, **C, **result;

    char filepath[256];
    
    sprintf(filepath, "Unit_test/unit_%s/C.txt", argv[1]);
    int expected_status = (is_file_empty(filepath)) ? -1 : 1;

    sprintf(filepath, "Unit_test/unit_%s/A.txt", argv[1]);
    read_matrix(filepath, &A, &A_row_size, &A_col_size, expected_status);

    sprintf(filepath, "Unit_test/unit_%s/B.txt", argv[1]);
    read_matrix(filepath, &B, &B_row_size, &B_col_size, expected_status);

    if (A_col_size != B_row_size) {
        handle_error("Matrix dimensions are incompatible for multiplication.", expected_status);
    }

    sprintf(filepath, "Unit_test/unit_%s/C.txt", argv[1]);
    read_matrix(filepath, &C, &C_row_size, &C_col_size, expected_status);

    if (A_row_size != C_row_size || B_col_size != C_col_size) {
        handle_error("Mismatch in Matrix dimensions.", expected_status);
    }

    result = calloc(A_row_size, sizeof(int *));
    for (int i = 0; i < A_row_size; i++) {  
        result[i] = calloc(B_col_size, sizeof(int));
    }

    char *variation = argv[2];
    clock_t start_time;
    clock_t end_time;
    double time_taken;

    // Call the appropriate matrix multiplication function based on the defined variation
    if (strcmp(variation, "ijk") == 0) {
        start_time = clock();
        matrix_multiply_ijk(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else if (strcmp(variation, "ikj") == 0) {
        start_time = clock();
        matrix_multiply_ikj(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else if (strcmp(variation, "jik") == 0) {
        start_time = clock();
        matrix_multiply_jik(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else if (strcmp(variation, "jki") == 0) {
        start_time = clock();
        matrix_multiply_jki(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else if (strcmp(variation, "kij") == 0) {
        start_time = clock();
        matrix_multiply_kij(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else if (strcmp(variation, "kji") == 0) {
        start_time = clock();
        matrix_multiply_kji(A, B, result, A_row_size, B_col_size, B_row_size);
        end_time = clock(); 
    } else {
        handle_error("Invalid variation.", MISC_ERROR);
    }

    time_taken = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC * 1000;
    if (compare_matrices(result, C, A_row_size, B_col_size)) {
        printf("Passed!,  %.3f ms\n", time_taken);
    } else {
        printf("Failed!, %.3f ms\n", time_taken);
    }

    for (int i = 0; i < A_row_size; i++) free(A[i]);
    for (int i = 0; i < B_row_size; i++) free(B[i]);
    for (int i = 0; i < C_row_size; i++) free(C[i]);
    for (int i = 0; i < A_row_size; i++) free(result[i]);
    free(A);
    free(B);
    free(C);
    free(result);

    return 0;
}
