#include "tiled.h"
#include "matrix.h"


void tiled_mm(float *out, float *in0, float *in1){
    //naive multiply and add respective blocks
    for(int b_col = 0; b_col < NUM_TILES; b_col++){
        for(int b_row = 0; b_row < NUM_TILES; b_row++){
            for(int intmd = 0; intmd < NUM_TILES; intmd++){ 
                tile_mult(out, in0, in1, intmd, b_col, b_row, intmd, b_row, b_col);
            }
        }
    } 

}

void tile_mult(float *out, float *in0, float *in1, int b_row0, int b_col0, int b_row1, int b_col1, int b_row_out, int b_col_out){
    int m_col1 = b_col1 * TILE_SIZE; 
    int m_row1 = b_row1 * TILE_SIZE;
    int m_col_out = b_col_out * TILE_SIZE;
    int m_row_out = b_row_out * TILE_SIZE;
    for(int m_col0 = b_col0 * TILE_SIZE;
            m_col0 < (b_col0 + 1) * TILE_SIZE; 
            m_col0++, m_col1++, m_col_out++){
        for(int m_row0 = b_row0 * TILE_SIZE; 
                m_row0 < (b_row0 + 1) * TILE_SIZE; 
                m_row0++, m_row1++, m_row_out++){
            for(int intmd = 0; intmd < TILE_SIZE; intmd++){
                int m_row0_intmd = intmd + (TILE_SIZE * b_row0);
                int m_row1_intmd = intmd + (TILE_SIZE * b_row1);
                int m_col0_intmd = intmd + (TILE_SIZE * b_col0);
                int m_col1_intmd = intmd + (TILE_SIZE * b_col1);
                //printf("mr0i=%d mc1i=%d mr0=%d mc0=%d\n", m_row0_intmd, m_col1_intmd, m_row0, m_col0);
                out[m_col_out * MATRIX_SIZE + m_row_out] = 
                    out[m_col_out * MATRIX_SIZE + m_row_out] + 
                    (in0[m_col0 * MATRIX_SIZE + m_row0_intmd] * 
                     in1[m_col1_intmd * MATRIX_SIZE + m_row1]);
            }
        }
        m_row1 = b_row1 * TILE_SIZE;
        m_row_out = b_row_out * TILE_SIZE;
    }
}
