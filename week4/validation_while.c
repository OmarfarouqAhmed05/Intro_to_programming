// ============================================================
// ACTIVITY 3A: INPUT VALIDATION WITH WHILE LOOP (C version)
// File: validation_while.c
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
    // We start it at 0 so it is never used without a value
    int number = 0;

    // Display a prompt asking for a positive number
    printf("Enter a positive number: ");

    // Read the first input from the user BEFORE the loop
    // This is necessary because the while loop checks the condition first
    // scanf returns 1 when it read a number successfully
    if (scanf("%d", &number) != 1) {
        clearInputLine();
        number = 0;   // treat letters as an invalid number
    }

    // While loop: checks condition BEFORE executing the body
    // If the user entered a valid number (positive), the loop never runs
    // If the user entered an invalid number, the loop repeats
    while (number <= 0) {

        // Display an error message
        printf("Invalid! Please enter a positive number: ");

        // Read a new input from the user
        if (scanf("%d", &number) != 1) {
            clearInputLine();
            number = 0;
        }

    } // End of while loop - condition is re-checked

    // This line runs only when a valid number is entered
    printf("You entered: %d\n", number);

    // Return 0 to signal successful completion
    return 0;
}