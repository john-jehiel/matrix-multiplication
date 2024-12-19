#include <stdlib.h>

void matrix_multiply_ijk(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int k = 0; k < m2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_ikj(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int i = 0; i < m1; i++) {
        for (int k = 0; k < m2; k++) {
            for (int j = 0; j < n2; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jik(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int j = 0; j < n2; j++) {
        for (int i = 0; i < m1; i++) {
            for (int k = 0; k < m2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_jki(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int j = 0; j < n2; j++) {
        for (int k = 0; k < m2; k++) {
            for (int i = 0; i < m1; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kij(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int k = 0; k < m2; k++) {
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n2; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_kji(int **A, int **B, int **C, int m1, int n2, int m2) {
    for (int k = 0; k < m2; k++) {
        for (int j = 0; j < n2; j++) {
            for (int i = 0; i < m1; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

