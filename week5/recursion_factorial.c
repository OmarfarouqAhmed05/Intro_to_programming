// ============================================================
// ACTIVITY 3: RECURSION - TWO FACTORIAL SOLUTIONS (C version)
// File: recursion_factorial.c
// Learning Outcome: Evaluate recursive solutions
// ============================================================

#include <stdio.h>

// ------------------------------------------------------------
// FUNCTION 1: factorialRecursive (Simple Recursion)
// Purpose: Calculate factorial using simple recursion
// Formula: n! = n * (n-1)!
// Base case: 0! = 1
// Note: long long is used instead of int so that results up to
//       20! fit without overflowing.
// ------------------------------------------------------------
long long factorialRecursive(int n) {
    // Base case: if n is 0 or 1, return 1
    if (n <= 1) {
        return 1;
    }

    // Recursive case: n * factorial of (n-1)
    // This creates a chain of multiplications after recursion returns
    return n * factorialRecursive(n - 1);
}

// ------------------------------------------------------------
// FUNCTION 2: factorialTail (Tail Recursion)
// Purpose: Calculate factorial using tail recursion
// Tail recursion: the recursive call is the LAST operation
// C has no default arguments, so the caller passes 1 for the
// accumulator (see main).
// ------------------------------------------------------------
long long factorialTail(int n, long long accumulator) {
    // Base case: if n is 0 or 1, return the accumulator
    if (n <= 1) {
        return accumulator;
    }

    // Tail recursive case: pass the accumulated product
    // The recursive call is the last thing the function does
    return factorialTail(n - 1, n * accumulator);
}

// The main function
int main() {
    int num;

    // Ask the user for a number
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &num);

    // Validate input
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    // 21! is too big even for long long, so we stop at 20
    if (num > 20) {
        printf("Number too large. Please use 20 or less.\n");
        return 1;
    }

    // Calculate using simple recursion (%lld prints a long long)
    printf("\nUsing simple recursion:\n");
    printf("  %d! = %lld\n", num, factorialRecursive(num));

    // Calculate using tail recursion (the accumulator starts at 1)
    printf("\nUsing tail recursion:\n");
    printf("  %d! = %lld\n", num, factorialTail(num, 1));

    // Comparison
    printf("\n--- Comparison ---\n");
    printf("Simple recursion: Clear, matches mathematical definition.\n");
    printf("Tail recursion: More efficient for large n (compiler optimization).\n");

    return 0;
}

// ------------------------------------------------------------
// STEP 5: TRACE OF SIMPLE RECURSION (n = 5)
// factorialRecursive(5)
//   = 5 * factorialRecursive(4)
//   = 5 * (4 * factorialRecursive(3))
//   = 5 * (4 * (3 * factorialRecursive(2)))
//   = 5 * (4 * (3 * (2 * factorialRecursive(1))))
//   = 5 * (4 * (3 * (2 * 1)))
//   = 5 * (4 * (3 * 2))
//   = 5 * (4 * 6)
//   = 5 * 24
//   = 120
//
// STEP 6: TRACE OF TAIL RECURSION (n = 5)
// factorialTail(5, 1)
//   = factorialTail(4, 5*1)  = factorialTail(4, 5)
//   = factorialTail(3, 4*5)  = factorialTail(3, 20)
//   = factorialTail(2, 3*20) = factorialTail(2, 60)
//   = factorialTail(1, 2*60) = factorialTail(1, 120)
//   = 120
// ------------------------------------------------------------