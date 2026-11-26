// ============================================================
// ACTIVITY 1: PASS-BY-VALUE - THE SWAP THAT DOESN'T SWAP (C version)
// File: swap_by_value.c
// Learning Outcome: Apply pass-by-value
// Also includes the Step 6 challenge. C has no references (&a),
// so "pass-by-reference" is done with POINTERS instead.
// ============================================================

// Include the standard input/output library
#include <stdio.h>

// ------------------------------------------------------------
// FUNCTION: swapByValue
// Purpose: Attempts to swap two integers
// Parameters: a and b (passed by value - copies are made)
// Returns: void (nothing)
// ------------------------------------------------------------
void swapByValue(int a, int b) {
    // Display the values inside the function before swapping
    printf("  Inside function - Before swap: a = %d, b = %d\n", a, b);

    // Declare a temporary variable to hold 'a'
    int temp = a;

    // Assign the value of 'b' to 'a'
    a = b;

    // Assign the value of 'temp' (original a) to 'b'
    b = temp;

    // Display the values inside the function after swapping
    printf("  Inside function - After swap:  a = %d, b = %d\n", a, b);

    // The function ends here. The original variables are NOT changed.
}

// ------------------------------------------------------------
// FUNCTION: swapByPointer (Step 6 challenge)
// Purpose: Swaps two integers for real
// Parameters: pointers to the original variables.
//             *a means "the value stored at address a".
// Returns: void (nothing)
// ------------------------------------------------------------
void swapByPointer(int *a, int *b) {
    int temp = *a;   // keep the original value that a points to
    *a = *b;         // change the caller's first variable
    *b = temp;       // change the caller's second variable
}

// The main function - where the program starts
int main() {
    // Declare two integer variables in main
    int x = 10;
    int y = 20;

    // ========================================================
    // PART 1: PASS-BY-VALUE (the swap fails)
    // ========================================================

    // Display the values before calling the function
    printf("Before calling swapByValue:\n");
    printf("  x = %d, y = %d\n", x, y);

    // Call the function, passing x and y by value
    // Copies of x and y are sent to the function
    swapByValue(x, y);

    // Display the values after calling the function
    printf("After calling swapByValue:\n");
    printf("  x = %d, y = %d\n", x, y);

    // Explain why the values did not change
    printf("\nExplanation: The function received COPIES of x and y.\n");
    printf("Changes made inside the function do not affect the originals.\n");

    // ========================================================
    // PART 2: PASS BY POINTER (the swap works)
    // ========================================================

    printf("\nBefore calling swapByPointer:\n");
    printf("  x = %d, y = %d\n", x, y);

    // &x and &y send the ADDRESSES of x and y, so the originals are swapped
    swapByPointer(&x, &y);

    printf("After calling swapByPointer:\n");
    printf("  x = %d, y = %d\n", x, y);

    printf("\nPassing addresses lets the function change the ORIGINAL variables.\n");

    // Return 0 to signal successful completion
    return 0;
}