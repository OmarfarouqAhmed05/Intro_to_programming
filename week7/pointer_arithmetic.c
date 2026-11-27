// ============================================================
// ACTIVITY 1: POINTER ARITHMETIC (C version)
// File: pointer_arithmetic.c
// Learning Outcome: Apply pointer arithmetic to traverse an array
// ============================================================

// Include the standard input/output library for printf
#include <stdio.h>

// The main function - where the program starts
int main() {

    // Declare and initialise an array of 5 integers
    // In memory, these are stored sequentially: e.g., at addresses 100, 104, 108...
    int numbers[5] = {10, 20, 30, 40, 50};

    // Declare a pointer named 'ptr' that points to an integer
    // We assign it the array name 'numbers'.
    // In C, an array name acts as a pointer to its first element.
    // So, ptr now holds the memory address of numbers[0] (which is 10).
    int *ptr = numbers;

    printf("Array elements accessed via pointer arithmetic:\n");

    // Loop 5 times to access each element
    for (int i = 0; i < 5; i++) {

        // *ptr means "dereference" - go to the address stored in ptr and get the value.
        // On the first iteration, this prints 10.
        printf("Value: %d\n", *ptr);

        // ARITHMETIC: ptr++ increments the pointer.
        // Because ptr is an int pointer, it increases the memory address by 4 bytes
        // (the size of an int), moving it to the next element in the array.
        ptr++;
    }

    // Reset the pointer back to the start of the array
    ptr = numbers;

    printf("\nAccessing using offset arithmetic:\n");

    // Another way to use pointer arithmetic: (ptr + i)
    for (int i = 0; i < 5; i++) {
        // *(ptr + i) is exactly the same as numbers[i]
        // It takes the base address (ptr) and jumps forward by i integers.
        printf("Index %d has value: %d\n", i, *(ptr + i));
    }

    // Extra: show that ptr + 1 moves forward by the SIZE OF AN INT (4 bytes),
    // not by 1 byte. (char *) lets us measure the distance in single bytes.
    printf("\nAddress arithmetic (each int is %zu bytes):\n", sizeof(int));
    printf("ptr     = %p\n", (void *)ptr);
    printf("ptr + 1 = %p\n", (void *)(ptr + 1));
    printf("Difference in bytes = %ld\n", (long)((char *)(ptr + 1) - (char *)ptr));

    return 0;
}