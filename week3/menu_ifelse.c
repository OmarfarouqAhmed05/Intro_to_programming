// ============================================================
// WEEK 3 PRACTICAL - PART 3: IF-ELSE VS SWITCH (C version)
// Program: Menu using an if-else chain
// File: menu_ifelse.c
// ============================================================

#include <stdio.h>   // printf and scanf

int main() {
    int choice;   // stores the menu option the user picks

    // Display the menu (\n starts a new line)
    printf("Menu:\n1. Start\n2. Load\n3. Settings\n4. Exit\nChoice: ");
    scanf("%d", &choice);

    // The chain checks each option from top to bottom.
    // The first condition that is true runs, the rest are skipped.
    if (choice == 1) {
        printf("Starting game...\n");
    } else if (choice == 2) {
        printf("Loading game...\n");
    } else if (choice == 3) {
        printf("Opening settings...\n");
    } else if (choice == 4) {
        printf("Exiting...\n");
    } else {
        // runs when none of the options above matched
        printf("Invalid choice!\n");
    }

    return 0;
}