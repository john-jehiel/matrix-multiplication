#include <stdlib.h>

void matrix_multiply_ijk(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int i = 0; i < A_row_size; i++) {
        for (int j = 0; j < B_col_size; j++) {
            for (int k = 0; k < B_row_size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_ikj(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int i = 0; i < A_row_size; i++) {
        for (int k = 0; k < B_row_size; k++) {
            for (int j = 0; j < B_col_size; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jik(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int j = 0; j < B_col_size; j++) {
        for (int i = 0; i < A_row_size; i++) {
            for (int k = 0; k < B_row_size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jki(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int j = 0; j < B_col_size; j++) {
        for (int k = 0; k < B_row_size; k++) {
            for (int i = 0; i < A_row_size; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kij(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int k = 0; k < B_row_size; k++) {
        for (int i = 0; i < A_row_size; i++) {
            for (int j = 0; j < B_col_size; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kji(float **A, float **B, float **C, int A_row_size, int B_col_size, int B_row_size) {
    for (int k = 0; k < B_row_size; k++) {
        for (int j = 0; j < B_col_size; j++) {
            for (int i = 0; i < A_row_size; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

