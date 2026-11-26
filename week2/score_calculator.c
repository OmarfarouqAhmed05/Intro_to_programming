// ============================================================
// WEEK 2 PRACTICAL: VARIABLES, DATA TYPES & BASIC I/O
// Program: Student Score Calculator (C version)
// File: score_calculator.c
// Includes the four Student Challenges:
//   1. a fourth test   2. letter grade   3. highest score   4. input validation
// ============================================================

#include <stdio.h>    // printf, scanf and fgets for output and input
#include <string.h>   // strcspn for removing the newline from text

#define SIZE 100      // maximum characters for the name and course

// Throws away everything left on the current input line.
// Used after a failed scanf so bad input does not repeat forever.
void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // keep reading until the end of the line
    }
}

// Reads one full line (including spaces) into buffer and removes the
// newline that fgets keeps. C equivalent of getline(cin, variable).
void readLine(char buffer[], int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// ------------------------------------------------------------
// FUNCTION: readScore
// Purpose: Asks for one test score and keeps asking until the
//          user enters a whole number from 0 to maxScore.
// Challenge 4: input validation
// ------------------------------------------------------------
int readScore(int testNumber, int maxScore) {
    int value;
    while (1) {
        printf("Enter score for Test %d: ", testNumber);
        // scanf returns 1 when it successfully read one integer
        if (scanf("%d", &value) != 1) {
            clearInputLine();
            printf("Error: please enter a whole number.\n");
        } else if (value < 0 || value > maxScore) {
            clearInputLine();
            printf("Error: score must be between 0 and %d.\n", maxScore);
        } else {
            clearInputLine();      // remove the leftover newline
            return value;          // valid score, give it back
        }
    }
}

int main() {

    // ============================================================
    // VARIABLE DECLARATIONS
    // C has no string type, so text is stored in char arrays.
    // ============================================================

    char studentName[SIZE];      // Text - stores the student's name
    char course[SIZE];           // Text - stores the course (BBIT/BCS)

    int score1, score2, score3, score4;   // Whole numbers - test scores (score4 is Challenge 1)
    int totalScore;                       // Whole number - sum of scores
    int highestScore;                     // Whole number - highest score (Challenge 3)

    double average;              // Decimal number - average score
    double percentage;           // Decimal number - percentage

    char grade;                  // Single character - letter grade (Challenge 2)

    // ============================================================
    // CONSTANT DECLARATIONS
    // const stops the value from being changed while the program runs.
    // ============================================================

    const int MAX_SCORE = 100;              // Maximum possible score per test
    const int NUM_TESTS = 4;                // Number of tests (Challenge 1)
    const int MAX_TOTAL = MAX_SCORE * NUM_TESTS;  // Maximum possible total (400)

    // ============================================================
    // WELCOME BANNER
    // printf displays text on the screen. \n moves to a new line.
    // ============================================================

    printf("========================================\n");
    printf("   STUDENT SCORE CALCULATOR\n");
    printf("========================================\n\n");

    // ============================================================
    // QUESTION 1: STUDENT NAME (full line, spaces allowed)
    // ============================================================

    printf("Enter student name: ");
    readLine(studentName, SIZE);

    // ============================================================
    // QUESTION 2: COURSE
    // ============================================================

    printf("Enter course (BBIT/BCS): ");
    readLine(course, SIZE);

    // ============================================================
    // QUESTION 3: TEST SCORES (validated)
    // ============================================================

    score1 = readScore(1, MAX_SCORE);
    score2 = readScore(2, MAX_SCORE);
    score3 = readScore(3, MAX_SCORE);
    score4 = readScore(4, MAX_SCORE);

    // ============================================================
    // CALCULATIONS
    // Dividing by 4.0 (a double) keeps the decimals.
    // Dividing by 4 (an int) would cut them off.
    // ============================================================

    totalScore = score1 + score2 + score3 + score4;
    average = totalScore / 4.0;
    percentage = (totalScore / (double)MAX_TOTAL) * 100;

    // ============================================================
    // CHALLENGE 3: HIGHEST SCORE
    // ============================================================

    highestScore = score1;
    if (score2 > highestScore) {
        highestScore = score2;
    }
    if (score3 > highestScore) {
        highestScore = score3;
    }
    if (score4 > highestScore) {
        highestScore = score4;
    }

    // ============================================================
    // CHALLENGE 2: LETTER GRADE (based on the percentage)
    // ============================================================

    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    // ============================================================
    // DISPLAY REPORT CARD
    // %d prints an int, %s prints text, %c prints one character,
    // %.2f prints a decimal with 2 places. %% prints a % sign.
    // ============================================================

    printf("\n========================================\n");
    printf("   REPORT CARD\n");
    printf("========================================\n\n");

    printf("Student:     %s\n", studentName);
    printf("Course:      %s\n\n", course);

    printf("Test 1:      %d/%d\n", score1, MAX_SCORE);
    printf("Test 2:      %d/%d\n", score2, MAX_SCORE);
    printf("Test 3:      %d/%d\n", score3, MAX_SCORE);
    printf("Test 4:      %d/%d\n\n", score4, MAX_SCORE);

    printf("Total:       %d/%d\n", totalScore, MAX_TOTAL);
    printf("Average:     %.2f\n", average);
    printf("Percentage:  %.2f%%\n", percentage);
    printf("Highest:     %d/%d\n", highestScore, MAX_SCORE);
    printf("Grade:       %c\n\n", grade);

    // Determine pass or fail (50% and above is a pass)
    if (percentage >= 50) {
        printf("Result:      PASS\n");
    } else {
        printf("Result:      FAIL\n");
    }

    printf("========================================\n");

    return 0;  // tells the operating system the program ran successfully
}