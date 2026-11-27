// ============================================================
// ACTIVITY 3: MEMORY LEAKS AND FREE (C version)
// File: memory_leaks.c
// Learning Outcome: Evaluate memory leak risks and fix them
// C uses malloc/free instead of C++ new/delete.
// Part A is the leak (createLeak). Part B is the fix (fixLeak).
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // malloc and free

// ------------------------------------------------------------
// ACTIVITY 3A: THE MEMORY LEAK
// A function that allocates memory but forgets to free it
// ------------------------------------------------------------
void createLeak(void) {
    // malloc allocates memory on the HEAP (dynamic memory) for one integer.
    // It returns the memory address, which we store in 'ptr'.
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    *ptr = 42;

    printf("Inside function. The value is: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void *)ptr);

    // THE LEAK: The function ends here.
    // The local variable 'ptr' is destroyed, but the memory on the heap
    // it was pointing to is NEVER freed. We have lost the address,
    // and the memory is now unreachable but still reserved by the OS.
}

// ------------------------------------------------------------
// ACTIVITY 3B: THE FIX
// The same function, but it frees the memory with free
// ------------------------------------------------------------
void fixLeak(void) {
    // Allocate memory
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    *ptr = 42;

    printf("Inside fixed function. Value: %d\n", *ptr);
    printf("Memory allocated at address: %p\n", (void *)ptr);

    // THE FIX: free gives the memory back to the operating system.
    free(ptr);

    // GOOD PRACTICE: Set the pointer to NULL after freeing it.
    // This prevents "dangling pointers" (pointers that point to freed memory).
    ptr = NULL;

    printf("Memory has been successfully freed.\n");
}

int main() {
    // --- Part A: the leak ---
    printf("--- Testing the Leak ---\n");
    printf("Calling function that leaks memory...\n");
    createLeak();
    printf("Function finished. The memory is now leaked.\n");

    // If we called createLeak() in a loop a million times,
    // the program would consume gigabytes of RAM and crash.

    // --- Part B: the fix ---
    printf("\n--- Testing the Fix ---\n");
    fixLeak();

    return 0;
}