#include "matrix.h"

float * generate_rand_input(int rows, int cols) {
    // ============================================
    // Allocating the matrices based on dimensions rows x cols
    // ============================================
    float * mat = malloc( rows * cols * sizeof(float));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i * cols + j] = rand() % 16;
        }
    }

    return mat;
}


float * generate_output(int rows, int cols) {
    // ============================================
    // Allocating the output matrix based on dimensions rows x cols
    // with 0's as initial value
    // ============================================
    float * mat = malloc( rows * cols * sizeof(float));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i * cols + j] = 0.0;
        }
    }

    return mat;
}


void print_mat(float * mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", mat[i * cols + j]);
        }
        printf("\n");
    }
}

// ============================================
// Implementation of naive matrix multiplication
// a = b * c
// a: matrix of dimension out_rows x out_cols
// b: matrix of dimension out_rows x in_cols
// c: matrix of dimension in_cols x out_cols
// ============================================
void naivemm(float * a, float * b, float * c, int out_rows, int out_cols, int in_cols) {
    for (int i = 0; i < out_rows; i++) {
        for (int j = 0; j < out_cols; j++) {
            for (int k = 0; k < in_cols; k++) {
                int a_index = i * out_cols + j;
                int b_index = i * in_cols + k;
                int c_index = k * out_cols + j;

                a[a_index] = a[a_index] + (b[b_index] * c[c_index]);
            }
        }
    }
}

void add_mat(float *out, float *in0, float *in1, int size){
    for(int col = 0; col < size; col++){
        for(int row = 0; row < size; row++){
            out[col * size + row] = in0[col * size + row] + in1[col * size + row];
        }
    }
}

// ============================================
// Comparing two matrices of the same size for correctness
// ============================================
bool compare_matrices(float * mat1, float * mat2, int rows, int cols) {
    bool equal = true;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i * cols + j;
            bool check = (mat1[index] == mat2[index]);
            equal = equal & check;
        }
    }
    return equal;
}


