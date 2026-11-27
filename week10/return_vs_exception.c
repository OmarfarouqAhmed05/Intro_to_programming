// ============================================================
// ACTIVITY 3: RETURN CODES VS EXCEPTIONS (C version)
// Learning Outcome: Evaluate exception handling strategies
// Note: data.txt does NOT exist on purpose, so both methods hit the error.
//
// NOTE: C has no exceptions (no try/throw/catch). METHOD 1 (return codes)
// is the normal C way. For METHOD 2 we imitate try/throw/catch with
// setjmp/longjmp: longjmp "throws" by jumping back to the spot saved by
// setjmp. It is low level and skips cleanup (open files are NOT closed
// when we jump), so real C code mostly sticks to return codes.
// ============================================================

#include <stdio.h>
#include <setjmp.h>

// METHOD 1: Using Return Codes (The old C way)
// Returns 1 (true) if successful, 0 (false) if failed.
int readFileWithReturnCode(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // We must manually pass the error back up
        return 0;
    }
    // ... read file ...
    fclose(file);
    return 1;
}

// METHOD 2: "Exceptions" with setjmp/longjmp
static jmp_buf catchPoint;          // the saved "catch" location
static const char *errorMessage;    // plays the role of the exception object

void readFileWithException(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // We actively "THROW": jump straight to the catch block
        errorMessage = "File not found";
        longjmp(catchPoint, 1);
    }
    // ... read file ...
    fclose(file);
}

int main() {
    printf("--- Testing Return Code Strategy ---\n");
    if (readFileWithReturnCode("data.txt") == 0) {
        printf("Return Code: Handled error gracefully. Program continues.\n");
    }

    printf("\n--- Testing Exception Strategy ---\n");
    // setjmp returns 0 the first time (the "try" block) and returns 1
    // when longjmp jumps back (the "catch" block).
    if (setjmp(catchPoint) == 0) {
        // "try"
        readFileWithException("data.txt");
    } else {
        // "catch"
        printf("Exception Caught: %s: data.txt\n", errorMessage);
        printf("Exception Strategy: Forced us to handle the error!\n");
    }

    return 0;
}

// ------------------------------------------------------------
// EVALUATE THE STRATEGIES
// 1. Return codes: simple, but easy to forget to check.
// 2. setjmp/longjmp: gives a try/catch feel, but skips cleanup, so it is
//    risky. C++ exceptions run destructors while unwinding, which makes
//    them much safer.
// ------------------------------------------------------------