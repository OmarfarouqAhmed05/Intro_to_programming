// ============================================================
// ACTIVITY 2: POINTERS VS REFERENCES (C version)
// File: pointers_vs_references.c
// Learning Outcome: Analyse code mixing pointers and references
// STEP 3: write down your predictions BEFORE you run the program.
//
// NOTE: C has NO references (int& is C++ only). The closest C idea is a
// CONSTANT pointer: "int *const refValue" must be given an address when it
// is declared and can never be re-pointed, just like a C++ reference.
// The difference is that we must write *refValue to use it.
// ============================================================

#include <stdio.h>

int main() {
    // 1. A normal integer variable
    int originalValue = 100;

    // 2. A "reference-like" CONSTANT pointer.
    // 'const' after the * means the pointer itself can never change.
    // It MUST be initialised when declared, and cannot refer to something else.
    int *const refValue = &originalValue;

    // 3. A normal POINTER variable.
    // The '*' means 'ptrValue' holds a memory address.
    // We use '&' (address-of operator) to get the address of originalValue.
    int *ptrValue = &originalValue;

    printf("--- Initial State ---\n");
    printf("originalValue: %d\n", originalValue);        // Expected: 100
    printf("refValue:      %d\n", *refValue);            // Expected: 100
    printf("ptrValue points to: %d\n", *ptrValue);       // Expected: 100 (* dereferences to get the value)

    // --- MODIFICATION 1 ---
    // Changing the value through the constant pointer changes the original variable.
    *refValue = 200;

    printf("\n--- After setting *refValue = 200 ---\n");
    printf("originalValue: %d\n", originalValue);        // Expected: 200
    printf("ptrValue points to: %d\n", *ptrValue);       // Expected: 200

    // --- MODIFICATION 2 ---
    // Changing the value via the pointer changes the original variable.
    *ptrValue = 300;   // *ptrValue means "the value AT the address"

    printf("\n--- After setting *ptrValue = 300 ---\n");
    printf("originalValue: %d\n", originalValue);        // Expected: 300
    printf("refValue:      %d\n", *refValue);            // Expected: 300

    // --- MODIFICATION 3 ---
    // We can change what a normal pointer points to.
    int anotherValue = 500;
    ptrValue = &anotherValue;   // Pointer now points to a different memory address

    printf("\n--- After pointing ptrValue to anotherValue ---\n");
    printf("originalValue: %d\n", originalValue);        // Expected: 300
    printf("ptrValue points to: %d\n", *ptrValue);       // Expected: 500

    // NOTE: We CANNOT do this with the constant pointer!
    // refValue = &anotherValue;   // ERROR: assignment of read-only variable

    return 0;
}