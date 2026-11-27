// ============================================================
// ACTIVITY 2: MEMORY LAYOUT OF 2D ARRAYS - ROW-MAJOR ORDER (C version)
// File: row_major.c
// Learning Outcome: Analyse the memory layout of a 2D array and its effect on traversal
// Includes the Step 6 challenge: column-major traversal
// ============================================================

#include <stdio.h>

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    // (#define-style sizes are used so the array size is a true constant in C)
    enum { ROWS = 3, COLS = 4 };
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Display the array in row-major order (row by row)
    printf("Row-major traversal (row by row):\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    // Display memory addresses to show the row-major layout
    // %p prints an address; it expects a (void *) pointer
    printf("\nMemory addresses (each int takes 4 bytes):\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("matrix[%d][%d] = %d at address %p\n",
                   row, col, matrix[row][col], (void *)&matrix[row][col]);
        }
    }

    // Explain the row-major order
    printf("\nObservation: Addresses increase row by row.\n");
    printf("Row 0 is stored completely, then row 1, then row 2.\n");
    printf("This is called ROW-MAJOR ORDER.\n");

    // ----------------------------------------------------------
    // STEP 6 CHALLENGE: COLUMN-MAJOR TRAVERSAL
    // The loops are swapped: the outer loop walks the columns and
    // the inner loop walks the rows. The OUTPUT order changes, but the
    // memory layout stays the same, so the addresses now JUMP around
    // (by 16 bytes = 4 ints) instead of moving forward by 4 bytes.
    // ----------------------------------------------------------
    printf("\nColumn-major traversal:\n");
    for (int col = 0; col < COLS; col++) {
        for (int row = 0; row < ROWS; row++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nMemory addresses while walking column by column:\n");
    for (int col = 0; col < COLS; col++) {
        for (int row = 0; row < ROWS; row++) {
            printf("matrix[%d][%d] at address %p\n",
                   row, col, (void *)&matrix[row][col]);
        }
    }
    printf("Notice the addresses jump by 16 bytes inside a column (poor cache use).\n");

    return 0;
}