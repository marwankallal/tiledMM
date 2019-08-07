#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_SIZE 8
#define NUM_TILES 1
#define TILE_SIZE (MATRIX_SIZE / NUM_TILES)
#define TILE_SIZE_SQ (TILE_SIZE * TILE_SIZE)


float * generate_rand_input(int rows, int cols);

float * generate_output(int rows, int cols);

void naivemm(float * a, float * b, float * c, int out_rows, int out_cols, int in_cols); 

void add_mat(float *out, float *in0, float *in1, int size);

void print_mat(float * mat, int rows, int cols);

bool compare_matrices(float * mat1, float * mat2, int rows, int cols);
