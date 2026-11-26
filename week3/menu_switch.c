// ============================================================
// WEEK 3 PRACTICAL - PART 3: IF-ELSE VS SWITCH (C version)
// Program: The same menu using a switch statement
// File: menu_switch.c
// ============================================================

#include <stdio.h>   // printf and scanf

int main() {
    int choice;   // stores the menu option the user picks

    printf("Menu:\n1. Start\n2. Load\n3. Settings\n4. Exit\nChoice: ");
    scanf("%d", &choice);

    // switch jumps straight to the matching case.
    // break stops the program from "falling through" into the next case.
    switch (choice) {
        case 1:
            printf("Starting game...\n");
            break;
        case 2:
            printf("Loading game...\n");
            break;
        case 3:
            printf("Opening settings...\n");
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            // default runs when no case matched (like the final else)
            printf("Invalid choice!\n");
    }

    return 0;
}