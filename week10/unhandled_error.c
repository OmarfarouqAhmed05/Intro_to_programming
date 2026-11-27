// ============================================================
// ACTIVITY 2: IGNORING FILE ERRORS (C version)
// Learning Outcome: Analyse unhandled file errors
//
// NOTE: In C the same mistake is WORSE. If fopen fails it returns NULL,
// and passing that NULL to fscanf usually CRASHES (segmentation fault),
// so that exact version cannot be run safely.
// This file shows the closest SAFE C version of the "silent failure":
// the file is missing, nothing is read, 'data' stays empty, and the
// program carries on as if nothing happened.
// ============================================================

#include <stdio.h>

int main() {
    // We are trying to open a file called "missing_file.txt" which DOES NOT EXIST.
    FILE *myFile = fopen("missing_file.txt", "r");   // returns NULL

    char data[100] = "";   // stays empty if nothing is read

    printf("Attempting to read from missing file...\n");

    // In C++ the failed stream quietly does nothing.
    // In C, fscanf(NULL, ...) would crash, so the only safe thing we can
    // do here is skip the read. 'data' stays empty, just like the C++ run.
    if (myFile != NULL) {
        fscanf(myFile, "%99s", data);   // ignoring the return value is the bug
        fclose(myFile);
    }

    // What will print here? Will the program crash? Will it print garbage?
    printf("Data read: %s\n", data);
    printf("Program continued running without crashing.\n");

    return 0;
}

// ------------------------------------------------------------
// ANALYSIS QUESTIONS (write these in your notebook)
// 1. Did the program crash?
//    Not in this safe version. But if we had called fscanf on the NULL
//    FILE*, C would crash. C++ streams fail silently instead.
// 2. What printed for data?
//    Nothing, because data stayed empty.
// 3. Why is this dangerous?
//    The program continues with empty or corrupted data (a bank balance
//    of 0). Always check that fopen did not return NULL.
// ------------------------------------------------------------