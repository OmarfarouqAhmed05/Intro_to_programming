// ============================================================
// WEEK 3 PRACTICAL - PART 2: NESTED CONDITIONALS (C version)
// Program: Order three numbers using nested if-else
// File: nested.c
// Part A: the nested version (6 execution paths)
// Part B: the simplified else-if version (Step 2.5)
// The program also checks that both versions give the same answer.
// ============================================================

#include <stdio.h>   // printf and scanf

int main() {
    int a, b, c;
    int pathNested = 0;   // path number found by the nested version
    int pathElseIf = 0;   // path number found by the else-if version

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    // ----------------------------------------------------------
    // PART A: NESTED VERSION
    // Each if/else splits into two branches, giving 6 possible paths.
    // ----------------------------------------------------------
    printf("\n--- Nested version ---\n");
    if (a > b) {
        if (b > c) {
            printf("Path 1: a > b > c\n");
            pathNested = 1;
        } else {
            if (a > c) {
                printf("Path 2: a > c > b\n");
                pathNested = 2;
            } else {
                printf("Path 3: c > a > b\n");
                pathNested = 3;
            }
        }
    } else {
        if (a > c) {
            printf("Path 4: b > a > c\n");
            pathNested = 4;
        } else {
            if (b > c) {
                printf("Path 5: b > c > a\n");
                pathNested = 5;
            } else {
                printf("Path 6: c > b > a\n");
                pathNested = 6;
            }
        }
    }

    // ----------------------------------------------------------
    // PART B: SIMPLIFIED ELSE-IF VERSION (Step 2.5)
    // The same decisions written as one flat chain.
    // ----------------------------------------------------------
    printf("\n--- Else-if version ---\n");
    if (a > b && b > c) {
        printf("Path 1: a > b > c\n");
        pathElseIf = 1;
    } else if (a > b && a > c) {
        printf("Path 2: a > c > b\n");
        pathElseIf = 2;
    } else if (a > b) {
        printf("Path 3: c > a > b\n");
        pathElseIf = 3;
    } else if (a > c) {
        printf("Path 4: b > a > c\n");
        pathElseIf = 4;
    } else if (b > c) {
        printf("Path 5: b > c > a\n");
        pathElseIf = 5;
    } else {
        printf("Path 6: c > b > a\n");
        pathElseIf = 6;
    }

    // ----------------------------------------------------------
    // COMPARE THE TWO VERSIONS
    // ----------------------------------------------------------
    if (pathNested == pathElseIf) {
        printf("\nBoth versions produced the same output.\n");
    } else {
        printf("\nThe versions are different!\n");
    }

    // ----------------------------------------------------------
    // STEP 2.4: DECISION TREE (draw this on paper too)
    //
    //                    a > b ?
    //               yes /        \ no
    //            b > c ?          a > c ?
    //          yes/   \no       yes/    \no
    //       Path 1   a > c ?   Path 4   b > c ?
    //                yes/ \no          yes/  \no
    //            Path 2  Path 3     Path 5  Path 6
    //
    // Test inputs:
    //   10 5 2  -> Path 1      10 2 5  -> Path 2
    //   5 2 10  -> Path 3      5 10 2  -> Path 4
    //   2 10 5  -> Path 5      2 5 10  -> Path 6
    // ----------------------------------------------------------

    return 0;
}