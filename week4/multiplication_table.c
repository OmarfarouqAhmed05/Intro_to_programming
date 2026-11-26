// ============================================================
// ACTIVITY 4: MULTIPLICATION TABLE USING NESTED LOOPS (C version)
// File: multiplication_table.c
// Learning Outcome: Create a nested loop structure
// Part 1 is the handout table (1 to 10).
// Part 2 covers the challenges: a 1 to 5 table with a header row.
// ============================================================

// Include the standard input/output library
#include <stdio.h>

// The main function
int main() {

    // ========================================================
    // PART 1: MULTIPLICATION TABLE (1 to 10)
    // ========================================================

    // Display a title for the multiplication table
    printf("========================================\n");
    printf("    MULTIPLICATION TABLE (1 to 10)\n");
    printf("========================================\n\n");

    // OUTER LOOP: Controls the rows (multiplicand 1 to 10)
    for (int i = 1; i <= 10; i++) {

        // INNER LOOP: Controls the columns (multiplier 1 to 10)
        // This loop runs completely for EACH iteration of the outer loop
        for (int j = 1; j <= 10; j++) {

            // Display the product with a field width of 5 characters
            // %5d is the C version of setw(5): it right-aligns in 5 spaces
            printf("%5d", i * j);

        } // End of inner loop - all columns for this row are printed

        // After the inner loop finishes, move to the next line
        printf("\n");

    } // End of outer loop - all rows are printed

    // Display a closing line
    printf("========================================\n");

    // ========================================================
    // PART 2: CHALLENGES
    // Challenge 1: table from 1 to 5 instead of 1 to 10
    // Challenge 2: header row (1 to 5) with a separator line
    // Challenge 3: try changing the width from 6 to 5 and see the alignment
    // ========================================================

    const int SIZE = 5;       // table size (change to 10 for the full table)
    const int WIDTH = 6;      // Challenge 3: field width of 6 spaces

    printf("\nCHALLENGE: TABLE FROM 1 TO %d WITH HEADER\n\n", SIZE);

    // Header row: column numbers 1 to SIZE
    // %*s and %*d let us pass the field width as an argument
    printf("%*s", WIDTH, " ");              // empty corner above the row labels
    for (int j = 1; j <= SIZE; j++) {
        printf("%*d", WIDTH, j);
    }
    printf("\n");

    // Separator line: one dash for every character in the row
    for (int k = 0; k < WIDTH * (SIZE + 1); k++) {
        printf("-");
    }
    printf("\n");

    // Table body: each row starts with its row number
    for (int i = 1; i <= SIZE; i++) {
        printf("%*d", WIDTH, i);            // row label
        for (int j = 1; j <= SIZE; j++) {
            printf("%*d", WIDTH, i * j);    // product
        }
        printf("\n");
    }

    // Return 0 to signal successful completion
    return 0;
}