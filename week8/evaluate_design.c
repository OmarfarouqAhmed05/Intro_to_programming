// ============================================================
// ACTIVITY 3: EVALUATING CLASS DESIGN (C version)
// File: evaluate_design.c
// Learning Outcome: Evaluate encapsulation violations
//
// NOTE: C has no 'private'. The "bad" design lets main() change the
// balance directly. The "good" design only changes it through a function
// that checks the rule. In C this is a coding discipline (real projects
// hide the struct inside a .c file so other files cannot reach the field).
// ============================================================

#include <stdio.h>

// ==========================================
// THE BAD DESIGN (Violation of Encapsulation)
// ==========================================
typedef struct {
    // Everything is open! Anyone can change the balance directly.
    double balance;
} BadBankAccount;

// ==========================================
// THE GOOD DESIGN (Proper Encapsulation)
// ==========================================
typedef struct {
    // Treat this as hidden. It must only be changed through the functions below.
    double balance;
} GoodBankAccount;

void good_init(GoodBankAccount *acc) {
    acc->balance = 0.0;
}

void good_deposit(GoodBankAccount *acc, double amount) {
    // The function checks the rule before changing the balance
    if (amount > 0) {
        acc->balance += amount;
    }
}

double good_getBalance(const GoodBankAccount *acc) {
    return acc->balance;
}

int main() {
    printf("--- Testing BAD Design ---\n");
    BadBankAccount badAccount;
    badAccount.balance = 0.0;
    // Direct access! No validation. We can hack the account.
    badAccount.balance = -5000;   // Impossible in real life!
    printf("Bad Account Balance: %g\n", badAccount.balance);

    printf("\n--- Testing GOOD Design ---\n");
    GoodBankAccount goodAccount;
    good_init(&goodAccount);

    // goodAccount.balance = -5000;   // Compiles in C, but breaks the rule. Never do this.
    // We must use the safe function.
    good_deposit(&goodAccount, 1000);
    printf("Good Account Balance: %g\n", good_getBalance(&goodAccount));

    // Extra: the safe function also rejects a negative deposit
    good_deposit(&goodAccount, -300);
    printf("Balance after trying to deposit -300: %g\n", good_getBalance(&goodAccount));

    return 0;
}

// ------------------------------------------------------------
// STEP 3: EVALUATE AND ANSWER
// 1. Why is the bad design dangerous?
//    Because any part of the program can modify balance without
//    validation, leading to impossible states like a negative balance.
// 2. How does the good design prevent this?
//    The only way to change the balance is the deposit function,
//    which has a built-in check: if (amount > 0).
// ------------------------------------------------------------