// ============================================================
// ACTIVITY 3B: INPUT VALIDATION WITH DO-WHILE LOOP (C version)
// File: validation_dowhile.c
// Learning Outcome: Evaluate while vs do-while for validation
// ============================================================

// Include the standard input/output library
#include <stdio.h>

// Throws away everything left on the current input line.
// Needed when the user types letters instead of a number.
void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // keep reading until the end of the line
    }
}

// The main function
int main() {

    // Declare an integer variable to store the user's input
    // We initialise it to 0 so the do-while loop will run at least once
    int number = 0;

    // do-while loop: executes the body FIRST, then checks the condition
    // This guarantees the body runs at least once
    do {

        // Display a prompt asking for a positive number
        printf("Enter a positive number: ");

        // Read the input from the user (written only once!)
        // If the user typed letters, set number to 0 so the loop repeats
        if (scanf("%d", &number) != 1) {
            clearInputLine();
            number = 0;
        }

        // Check if the input is invalid and display an error
        if (number <= 0) {
            printf("Invalid! ");
        }

    } while (number <= 0);   // Condition checked AFTER the body runs

    // This line runs only when a valid number is entered
    printf("You entered: %d\n", number);

    // Return 0 to signal successful completion
    return 0;
}