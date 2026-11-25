#include <stdio.h> // printf and fgets for output and input
#include <string.h> // strlen and strcspn for working with text

#define SIZE 200 // maximum number of characters for each answer

// Reads one full line (including spaces) into buffer and removes the
// newline character that fgets leaves at the end.
// This is the C equivalent of getline(cin, variable) in C++.
void readLine(char buffer[], int size) {
fgets(buffer, size, stdin);
buffer[strcspn(buffer, "\n")] = '\0'; // replace the newline with the end-of-text marker
}

int main() {
// ============================================================
// VARIABLE DECLARATIONS
// C has no string type, so text is stored in arrays of characters
// ============================================================
char name[SIZE];         // Stores the user's name
char course[SIZE];       // Stores the course (BBIT or BCS)
char hobby[SIZE];        // Stores the hobby
char reason[SIZE];       // Stores why they chose the course
char expectation[SIZE];  // Stores what they expect to learn
char definition[SIZE];   // Stores their definition of programming
char food[SIZE];         // Challenge 1: stores the favourite food
char dreamJob[SIZE];     // Challenge 1: stores the dream job

// ============================================================
// WELCOME MESSAGE
// ============================================================
printf("========================================\n");
printf("   WELCOME TO YOUR FIRST PROGRAM!\n");
printf("========================================\n\n");

// ============================================================
// QUESTION 1: NAME
// ============================================================
printf("1. What is your name? ");
readLine(name, SIZE);

// Challenge 2: validation, check if the user entered nothing
if (strlen(name) == 0) {
    printf("You didn't enter a name!\n");
    strcpy(name, "Student");  // fallback name so the rest of the program still works
}

// ============================================================
// QUESTION 2: COURSE (BBIT or BCS)
// ============================================================
printf("2. What course are you doing? (BBIT/BCS): ");
readLine(course, SIZE);

// ============================================================
// QUESTION 3: HOBBY
// ============================================================
printf("3. What is your hobby? ");
readLine(hobby, SIZE);

// ============================================================
// QUESTION 4: REASON FOR CHOOSING THE COURSE
// ============================================================
printf("4. Why did you choose this course? ");
readLine(reason, SIZE);

// ============================================================
// QUESTION 5: EXPECTATIONS
// ============================================================
printf("5. What do you expect to learn in programming? ");
readLine(expectation, SIZE);

// ============================================================
// QUESTION 6: DEFINITION OF PROGRAMMING
// ============================================================
printf("6. In your own words, what is programming? ");
readLine(definition, SIZE);

// ============================================================
// CHALLENGE 1: EXTRA QUESTIONS
// ============================================================
printf("7. What is your favourite food? ");
readLine(food, SIZE);

printf("8. What is your dream job? ");
readLine(dreamJob, SIZE);

// ============================================================
// DISPLAY THE SUMMARY
// %s is the placeholder that prints a piece of text
// ============================================================
printf("\n========================================\n");
printf("          YOUR PROFILE SUMMARY\n");
printf("========================================\n\n");

printf("Name:           %s\n", name);
printf("Course:         %s\n", course);
printf("Hobby:          %s\n", hobby);
printf("Reason:         %s\n", reason);
printf("Expectation:    %s\n", expectation);
printf("Programming is: %s\n", definition);
printf("Favourite food: %s\n", food);
printf("Dream job:      %s\n\n", dreamJob);

// ============================================================
// CHALLENGE 3: PERSONALISED FINAL MESSAGE
// ============================================================
printf("========================================\n");
printf("Great job, %s! You are on your way to becoming a programmer!\n", name);
printf("========================================\n");

return 0;  // tells the operating system the program ran successfully
}