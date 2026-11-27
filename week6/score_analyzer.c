// ============================================================
// ACTIVITY 4: STUDENT SCORE ANALYZER (C version)
// File: score_analyzer.c
// Learning Outcome: Create a program that reads scores, calculates
// average, and displays scores above average
// Includes all four Step 5 challenges:
//   1. highest score and position     2. lowest score and position
//   3. count of scores above average  4. dynamic size (malloc, since C has no vector)
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // malloc and free (dynamic size, Challenge 4)

// Throws away everything left on the current input line.
// Used after a failed scanf so bad input does not repeat forever.
void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // keep reading until the end of the line
    }
}

// ------------------------------------------------------------
// FUNCTION: calculateAverage
// Purpose: Calculate the average of an array of scores
// Parameters: scores (array), size (number of elements)
// Returns: average (double)
// ------------------------------------------------------------
double calculateAverage(int scores[], int size) {
    int sum = 0;
    // Loop through each score and add to sum
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    // Return the average as a double
    // (double)sum makes the division keep its decimals
    return (double)sum / size;
}

// ------------------------------------------------------------
// FUNCTION: displayAboveAverage
// Purpose: Display scores that are above the average
// Parameters: scores (array), size (number of elements), average
// Returns: void
// ------------------------------------------------------------
void displayAboveAverage(int scores[], int size, double average) {
    printf("\nScores above average (%.2f):\n", average);
    int found = 0;   // 0 = none found yet, 1 = at least one found

    // Loop through each score and compare with average
    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            printf("  Score %d at position %d\n", scores[i], i + 1);
            found = 1;
        }
    }

    // If no scores are above average, display a message
    if (!found) {
        printf("  None\n");
    }
}

// ------------------------------------------------------------
// CHALLENGE 1: FUNCTION findHighest
// Purpose: Find the highest score and where it is
// Parameters: scores (array), size, position (a POINTER: the function
//             writes the position back into the caller's variable)
// Returns: the highest score
// ------------------------------------------------------------
int findHighest(int scores[], int size, int *position) {
    int highest = scores[0];   // assume the first score is the highest
    *position = 1;             // positions are shown from 1
    for (int i = 1; i < size; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
            *position = i + 1;
        }
    }
    return highest;
}

// ------------------------------------------------------------
// CHALLENGE 2: FUNCTION findLowest
// Purpose: Find the lowest score and where it is
// ------------------------------------------------------------
int findLowest(int scores[], int size, int *position) {
    int lowest = scores[0];    // assume the first score is the lowest
    *position = 1;
    for (int i = 1; i < size; i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
            *position = i + 1;
        }
    }
    return lowest;
}

// ------------------------------------------------------------
// CHALLENGE 3: FUNCTION countAboveAverage
// Purpose: Count how many scores are above the average
// ------------------------------------------------------------
int countAboveAverage(int scores[], int size, double average) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] > average) {
            count++;
        }
    }
    return count;
}

// The main function
int main() {
    // ----------------------------------------------------------
    // CHALLENGE 4: ask how many scores to enter (dynamic size)
    // Keep asking until the user enters a whole number of 1 or more.
    // ----------------------------------------------------------
    int size;
    printf("How many scores do you want to enter? ");
    while (scanf("%d", &size) != 1 || size < 1) {
        clearInputLine();   // throw away the bad input
        printf("Please enter a whole number of 1 or more: ");
    }

    // malloc reserves memory for 'size' integers on the heap
    int *scores = malloc(size * sizeof(int));
    if (scores == NULL) {
        printf("Out of memory.\n");
        return 1;
    }

    // Ask the user to enter the scores
    printf("Enter %d student scores:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Score %d: ", i + 1);
        // Validate: the score must be a whole number from 0 to 100
        while (scanf("%d", &scores[i]) != 1 || scores[i] < 0 || scores[i] > 100) {
            clearInputLine();
            printf("Invalid! Enter a score from 0 to 100: ");
        }
    }

    // Calculate the average
    double average = calculateAverage(scores, size);

    // Display the results
    printf("\n--- Results ---\n");
    printf("Average score: %.2f\n", average);

    // Display scores above average
    displayAboveAverage(scores, size, average);

    // Challenges 1 to 3
    int position;
    int highest = findHighest(scores, size, &position);
    printf("\nHighest score: %d at position %d\n", highest, position);

    int lowest = findLowest(scores, size, &position);
    printf("Lowest score: %d at position %d\n", lowest, position);

    printf("Number of scores above average: %d\n",
           countAboveAverage(scores, size, average));

    // Give the memory back (every malloc needs a matching free)
    free(scores);

    return 0;
}