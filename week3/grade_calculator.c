// ============================================================
// WEEK 3 PRACTICAL - PART 4: GRADING PROGRAM (C version)
// Program: Grade Calculator
// File: grade_calculator.c
// Includes: letter grades, plus/minus modifiers (Step 4.1),
//           personalised messages (Step 4.3) and handling many
//           students in a loop with a summary (Step 4.4).
// ============================================================

#include <stdio.h>    // printf, scanf and fgets
#include <string.h>   // strcspn for removing the newline

#define SIZE 100      // maximum characters for a student's name

// Throws away everything left on the current input line.
void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // keep reading until the end of the line
    }
}

int main() {

    printf("===== GRADE CALCULATOR =====\n");

    // ----------------------------------------------------------
    // STEP 4.4: HOW MANY STUDENTS?
    // Keep asking until the number is at least 1.
    // ----------------------------------------------------------
    int numStudents;
    printf("How many students? ");
    while (scanf("%d", &numStudents) != 1 || numStudents < 1) {
        clearInputLine();          // throw away the bad input
        printf("Please enter a whole number of 1 or more: ");
    }
    clearInputLine();              // remove the newline before using fgets

    // Counters for the summary at the end
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

    // ----------------------------------------------------------
    // LOOP: one pass for each student
    // ----------------------------------------------------------
    for (int student = 1; student <= numStudents; student++) {

        char name[SIZE];
        double score;
        char grade;
        char modifier = ' ';   // space means no modifier

        printf("\n--- Student %d of %d ---\n", student, numStudents);

        // Read the student's name (fgets allows spaces)
        printf("Enter student name: ");
        fgets(name, SIZE, stdin);
        name[strcspn(name, "\n")] = '\0';   // remove the newline fgets keeps

        // Input validation: the score must be between 0 and 100
        printf("Enter percentage score (0-100): ");
        while (scanf("%lf", &score) != 1 || score < 0 || score > 100) {
            clearInputLine();
            printf("Invalid score! Must be between 0 and 100. Try again: ");
        }
        clearInputLine();

        // ------------------------------------------------------
        // DETERMINE BASE LETTER GRADE (multiple cut-offs)
        // ------------------------------------------------------
        if (score >= 90) {
            grade = 'A';
        } else if (score >= 80) {
            grade = 'B';
        } else if (score >= 70) {
            grade = 'C';
        } else if (score >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        // ------------------------------------------------------
        // DETERMINE PLUS/MINUS MODIFIER (only for A, B, C, D)
        // lastDigit is the units digit of the score (e.g. 87 -> 7)
        // NOTE: the handout's test table says 83 -> B, so a minus
        // is given only when the last digit is 2 or less.
        // ------------------------------------------------------
        if (grade != 'F') {
            int lastDigit = (int)score % 10;

            if (grade == 'A') {
                if (score >= 97) modifier = '+';
                else if (score < 93) modifier = '-';
            } else {   // B, C and D use the last digit
                if (lastDigit >= 7) modifier = '+';
                else if (lastDigit <= 2) modifier = '-';
            }
        }

        // ------------------------------------------------------
        // COUNT THE GRADE FOR THE SUMMARY (switch on the letter)
        // ------------------------------------------------------
        switch (grade) {
            case 'A': countA++; break;
            case 'B': countB++; break;
            case 'C': countC++; break;
            case 'D': countD++; break;
            default:  countF++; break;
        }

        // ------------------------------------------------------
        // DISPLAY RESULT
        // %.1f prints a decimal with 1 place, %c prints one character
        // ------------------------------------------------------
        printf("\nStudent: %s\n", name);
        printf("Score: %.1f%%\n", score);
        printf("Grade: %c", grade);
        if (modifier != ' ') printf("%c", modifier);
        printf("\n");

        // ------------------------------------------------------
        // STEP 4.3: PERSONALISED MESSAGE FOR EACH GRADE
        // ------------------------------------------------------
        switch (grade) {
            case 'A': printf("Excellent work!\n");    break;
            case 'B': printf("Good job!\n");          break;
            case 'C': printf("Satisfactory.\n");      break;
            case 'D': printf("Needs improvement.\n"); break;
            default:  printf("Please seek help.\n");  break;
        }
    }

    // ----------------------------------------------------------
    // SUMMARY OF ALL GRADES
    // ----------------------------------------------------------
    printf("\n===== SUMMARY =====\n");
    printf("Students: %d\n", numStudents);
    printf("A's: %d\n", countA);
    printf("B's: %d\n", countB);
    printf("C's: %d\n", countC);
    printf("D's: %d\n", countD);
    printf("F's: %d\n", countF);

    return 0;
}