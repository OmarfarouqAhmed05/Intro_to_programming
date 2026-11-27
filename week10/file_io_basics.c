// ============================================================
// ACTIVITY 1: BASIC FILE I/O (C version)
// Learning Outcome: Read numbers from a file, sum them, write to a file
// Needs: numbers.txt in the same folder (10, 25, 5, 40, 12 - one per line)
//
// NOTE: C uses a FILE* with fopen / fscanf / fprintf / fclose instead of
// ifstream and ofstream.
// ============================================================

#include <stdio.h>

int main() {
    // 1. OPEN FILE FOR READING (INPUT)
    // "r" = read. fopen returns NULL if it fails.
    FILE *inputFile = fopen("numbers.txt", "r");

    // Check if the file was successfully opened
    if (inputFile == NULL) {
        printf("Error: Could not open numbers.txt for reading!\n");
        return 1;   // Exit with error code
    }

    int num;
    int sum = 0;

    printf("Reading numbers from file...\n");

    // 2. READ DATA IN A LOOP
    // fscanf returns how many values it read. 1 means success; at the end
    // of the file it returns EOF, so the loop stops.
    while (fscanf(inputFile, "%d", &num) == 1) {
        printf("Read: %d\n", num);
        sum += num;
    }

    // 3. CLOSE THE FILE
    fclose(inputFile);

    printf("Total Sum: %d\n", sum);

    // 4. OPEN FILE FOR WRITING (OUTPUT)
    // "w" = write. Creates sum.txt, or overwrites it if it exists!
    FILE *outputFile = fopen("sum.txt", "w");

    if (outputFile == NULL) {
        printf("Error: Could not create sum.txt for writing!\n");
        return 1;
    }

    // 5. WRITE DATA TO THE FILE
    fprintf(outputFile, "The total sum is: %d\n", sum);
    fprintf(outputFile, "Calculated automatically by the C program.\n");

    // 6. CLOSE THE OUTPUT FILE
    fclose(outputFile);

    printf("Result successfully saved to sum.txt!\n");

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 1)
// - #include <stdio.h> gives us FILE, fopen, fscanf, fprintf, fclose.
// - Always check that fopen did not return NULL.
// - Loop on the return value of fscanf.
// - Always fclose() files when finished.
// Expected: Total Sum: 92, and sum.txt is created.
// ------------------------------------------------------------