// ============================================================
// ACTIVITY 4: MULTIPLICATION TABLE USING NESTED LOOPS
// File: multiplication_table.cpp
// Learning Outcome: Create a nested loop structure
// Part 1 is the handout table (1 to 10).
// Part 2 covers the challenges: a 1 to 5 table with a header row.
// ============================================================

// Include the input/output library
#include <iostream>

// Include the iomanip library for setw (field width formatting)
#include <iomanip>

// Use the standard namespace
using namespace std;

// The main function
int main() {

    // ========================================================
    // PART 1: MULTIPLICATION TABLE (1 to 10)
    // ========================================================

    // Display a title for the multiplication table
    cout << "========================================" << endl;
    cout << "    MULTIPLICATION TABLE (1 to 10)" << endl;
    cout << "========================================" << endl;
    cout << endl;

    // OUTER LOOP: Controls the rows (multiplicand 1 to 10)
    // Part 1: int i = 1;  -> Start with row 1
    // Part 2: i <= 10;    -> Continue until row 10
    // Part 3: i++         -> Move to the next row
    for (int i = 1; i <= 10; i++) {

        // INNER LOOP: Controls the columns (multiplier 1 to 10)
        // This loop runs completely for EACH iteration of the outer loop
        // Part 1: int j = 1;  -> Start with column 1
        // Part 2: j <= 10;    -> Continue until column 10
        // Part 3: j++         -> Move to the next column
        for (int j = 1; j <= 10; j++) {

            // Display the product with a field width of 5 characters
            // setw(5) ensures each number takes up 5 spaces for alignment
            cout << setw(5) << i * j;

        } // End of inner loop - all columns for this row are printed

        // After the inner loop finishes, move to the next line
        // This starts a new row for the next value of i
        cout << endl;

    } // End of outer loop - all rows are printed

    // Display a closing line
    cout << "========================================" << endl;

    // ========================================================
    // PART 2: CHALLENGES
    // Challenge 1: table from 1 to 5 instead of 1 to 10
    // Challenge 2: header row (1 to 5) with a separator line
    // Challenge 3: try changing setw(5) to setw(6) and see the alignment
    // ========================================================

    const int SIZE = 5;       // table size (change to 10 for the full table)
    const int WIDTH = 6;      // Challenge 3: field width of 6 spaces

    cout << endl;
    cout << "CHALLENGE: TABLE FROM 1 TO " << SIZE << " WITH HEADER" << endl;
    cout << endl;

    // Header row: column numbers 1 to SIZE
    cout << setw(WIDTH) << " ";            // empty corner above the row labels
    for (int j = 1; j <= SIZE; j++) {
        cout << setw(WIDTH) << j;
    }
    cout << endl;

    // Separator line: one dash for every character in the row
    cout << string(WIDTH * (SIZE + 1), '-') << endl;

    // Table body: each row starts with its row number
    for (int i = 1; i <= SIZE; i++) {
        cout << setw(WIDTH) << i;          // row label
        for (int j = 1; j <= SIZE; j++) {
            cout << setw(WIDTH) << i * j;  // product
        }
        cout << endl;
    }

    // Return 0 to signal successful completion
    return 0;
}