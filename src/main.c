
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "matrix.h"
#include "tiled.h"


int main() {

    int MATRIX_ROWS = MATRIX_SIZE;
    int MATRIX_COLS = MATRIX_ROWS; // for a square matrix

    clock_t start_clock, end_clock;
    double cpu_time;
    int number_of_iterations = 10; // TODO: Set this for consistent results

    float * mat_a = generate_output(MATRIX_ROWS, MATRIX_COLS);
    float *mat_a_tiled = generate_output(MATRIX_ROWS, MATRIX_COLS);
    float * mat_b = generate_rand_input(MATRIX_ROWS, MATRIX_COLS);
    float * mat_c = generate_rand_input(MATRIX_ROWS, MATRIX_COLS);
	
    // ============================================
    // Running and profiling
    // ============================================
    start_clock = clock();
    for (int iter = 0; iter < number_of_iterations; iter++) {
        naivemm(mat_a, mat_b, mat_c, MATRIX_ROWS, MATRIX_COLS, MATRIX_COLS);
    }
    end_clock = clock();

    // Print final output matrix for debugging purposes. Can comment out if not
    // needed.
    //
    /*
    print_mat(mat_a, MATRIX_ROWS, MATRIX_COLS);
    printf("\n");
    print_mat(mat_b, MATRIX_ROWS, MATRIX_COLS);
    printf("\n");
    print_mat(mat_c, MATRIX_SIZE, MATRIX_SIZE);
    */
    // TODO: Comparing matrices with golden matrix-multiplication implementation
    // (naive). Change this code to verify that optimized tiled implementation is
    // also correct.
    if ( compare_matrices(mat_a, mat_a, MATRIX_ROWS, MATRIX_COLS) ) {
        printf("Matrix multiplication (naive) is functionally correct.\n");
    } else {
        printf("[Error] Matrix multiplication (tiled) is not functionally correct...\n");
    }

    // Compute execution time.
    printf("=========================================\n");
    cpu_time = ( (double) (end_clock - start_clock) ) / CLOCKS_PER_SEC;
    printf("Total execution time: \t\t %lf seconds \n", cpu_time);
    cpu_time = cpu_time / (double) number_of_iterations; // time per iteration
    printf("Per iteration execution time: \t %lf seconds \n", cpu_time);
    printf("=========================================\n");

    start_clock = clock();
    for(int i = 0; i < number_of_iterations; i++){
        tiled_mm(mat_a_tiled, mat_b, mat_c);
    }
    end_clock = clock();

    //print_mat(mat_a_tiled, MATRIX_ROWS, MATRIX_COLS);

    if ( compare_matrices(mat_a, mat_a_tiled, MATRIX_ROWS, MATRIX_COLS) ) {
        printf("Matrix multiplication (tiled) is functionally correct.\n");
    } else {
        printf("[Error] Matrix multiplication (tiled) is not functionally correct...\n");
    }

    // Compute execution time.
    printf("=========================================\n");
    cpu_time = ( (double) (end_clock - start_clock) ) / CLOCKS_PER_SEC;
    printf("Total execution time: \t\t %lf seconds \n", cpu_time);
    cpu_time = cpu_time / (double) number_of_iterations; // time per iteration
    printf("Per iteration execution time: \t %lf seconds \n", cpu_time);
    printf("=========================================\n");

    // ============================================
    // Freeing matrices before ending the code
    // ============================================
    free(mat_a);
    free(mat_b);
    free(mat_c);


    return 0;
}

