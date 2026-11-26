// ============================================================
// WEEK 3 PRACTICAL - PART 1: LOGICAL OPERATORS (C version)
// Program: Event Eligibility Checker
// File: conditionals.c
// Uses && (AND), || (OR) and ! (NOT) to build a complex condition.
// ============================================================

#include <stdio.h>     // printf and scanf
#include <stdbool.h>   // gives us bool, true and false in C

int main() {

    // ----------------------------------------------------------
    // VARIABLES
    // scanf cannot read a bool directly, so we read whole numbers
    // (1 or 0) and then convert them to bool.
    // ----------------------------------------------------------
    int age;
    int ticketInput, memberInput, bannedInput, parentInput = 0;
    bool hasTicket, isMember, isBanned;
    bool hasParent = false;   // Step 1.6: only asked when the person is under 16

    // ----------------------------------------------------------
    // GET USER INPUT
    // ----------------------------------------------------------
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Do you have a ticket? (1 for yes, 0 for no): ");
    scanf("%d", &ticketInput);

    printf("Are you a member? (1 for yes, 0 for no): ");
    scanf("%d", &memberInput);

    printf("Are you banned? (1 for yes, 0 for no): ");
    scanf("%d", &bannedInput);

    // Convert the numbers to bool (any non-zero number becomes true)
    hasTicket = (ticketInput != 0);
    isMember  = (memberInput != 0);
    isBanned  = (bannedInput != 0);

    // Step 1.6: people under 16 need a parent with them
    if (age < 16) {
        printf("Do you have a parent with you? (1 for yes, 0 for no): ");
        scanf("%d", &parentInput);
        hasParent = (parentInput != 0);
    }

    // ----------------------------------------------------------
    // APPLY LOGICAL OPERATORS
    // Original rule:
    //   Eligible if: age >= 18 AND has ticket AND NOT banned
    //   OR:          is a member AND NOT banned
    // ----------------------------------------------------------
    bool canEnterOriginal = (age >= 18 && hasTicket && !isBanned) ||
                            (isMember && !isBanned);

    // ----------------------------------------------------------
    // STEP 1.6: REWRITTEN EXPRESSION WITH THE PARENT RULE
    // Nobody who is banned can enter. Then either an adult with a
    // ticket OR a member can enter. Finally, anyone under 16 must
    // have a parent with them.
    // ----------------------------------------------------------
    bool canEnter = !isBanned &&
                    ((age >= 18 && hasTicket) || isMember) &&
                    (age >= 16 || hasParent);

    // Show the result
    if (canEnter) {
        printf("You can enter the event!\n");
    } else {
        printf("Sorry, you cannot enter.\n");
    }

    // Small note to show what the original rule (without the parent rule) said
    printf("(Original rule without the parent check: %s)\n",
           canEnterOriginal ? "enter" : "no entry");

    return 0;  // program ended successfully
}