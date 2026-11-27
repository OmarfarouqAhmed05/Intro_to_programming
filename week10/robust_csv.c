// ============================================================
// ACTIVITY 4: ROBUST CSV PARSER (C version)
// Learning Outcome: Read CSV, compute GPA, handle malformed lines
// Needs: students.csv in the same folder
//
// NOTE: C has no stringstream, no stoi and no exceptions. Instead:
//   - fgets reads one line
//   - strtok_r-style splitting is done with strchr (it is safer)
//   - strtol converts text to a number AND tells us if it failed
//     (through an "end pointer"). That failure check is the C
//     equivalent of stoi throwing invalid_argument.
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // strtol
#include <string.h>   // strchr, strcspn

// Convert text to int. Returns 1 on success, 0 if the text is not a number.
// This plays the role of stoi throwing invalid_argument.
int toInt(const char *text, int *out) {
    char *end;
    long v = strtol(text, &end, 10);
    // end == text    -> nothing was converted (e.g. "Error")
    // *end != '\0'   -> extra characters after the number (e.g. "12abc")
    if (end == text || *end != '\0') return 0;
    *out = (int)v;
    return 1;
}

int main() {
    // Open the file
    FILE *file = fopen("students.csv", "r");

    // 1. HANDLE MISSING FILE GRACEFULLY
    if (file == NULL) {
        printf("Error: Could not find students.csv!\n");
        return 1;
    }

    char line[256];

    printf("--- Processing Student Records ---\n");

    // 2. READ THE FILE LINE BY LINE
    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the newline that fgets keeps
        line[strcspn(line, "\r\n")] = '\0';

        // Skip empty lines
        if (line[0] == '\0') continue;

        // Split the line at the commas by hand: name,s1,s2,s3
        char *name = line;
        char *p1 = strchr(name, ',');
        if (p1 == NULL) {
            printf("WARNING: Skipping malformed record (missing fields).\n");
            continue;
        }
        *p1 = '\0';
        char *scoreStr1 = p1 + 1;

        char *p2 = strchr(scoreStr1, ',');
        if (p2 == NULL) {
            printf("WARNING: Skipping malformed record for %s (missing fields).\n", name);
            continue;
        }
        *p2 = '\0';
        char *scoreStr2 = p2 + 1;

        char *p3 = strchr(scoreStr2, ',');
        if (p3 == NULL) {
            printf("WARNING: Skipping malformed record for %s (missing fields).\n", name);
            continue;
        }
        *p3 = '\0';
        char *scoreStr3 = p3 + 1;

        // 3. ERROR HANDLING FOR MALFORMED DATA
        int s1, s2, s3;
        if (toInt(scoreStr1, &s1) && toInt(scoreStr2, &s2) && toInt(scoreStr3, &s3)) {
            // Calculate Average
            double average = (s1 + s2 + s3) / 3.0;
            printf("%s -> Average: %g\n", name, average);
        } else {
            // Same message as the C++ catch block. We then simply carry on
            // to the next line.
            printf("WARNING: Skipping malformed record for %s (Invalid score data).\n", name);
        }
    }

    fclose(file);
    printf("\n--- Processing Complete ---\n");

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 4)
// - fgets + manual splitting replace stringstream + getline.
// - strtol with the end-pointer check replaces stoi + try/catch.
// - (atoi cannot report failure: atoi("Error") silently gives 0.)
//
// Expected output:
// --- Processing Student Records ---
// Alice -> Average: 87.6667
// Bob -> Average: 75
// WARNING: Skipping malformed record for Charlie (Invalid score data).
// Diana -> Average: 95
// --- Processing Complete ---
// ------------------------------------------------------------