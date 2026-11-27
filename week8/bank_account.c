// ============================================================
// ACTIVITY 4: BANK ACCOUNT CLASS (C version)
// File: bank_account.c
// Learning Outcome: Create a "class" with methods and validation
//
// NOTE: C has no classes, so BankAccount is a struct and the
// "methods" are functions that receive a pointer to the account.
// ============================================================

#include <stdio.h>
#include <string.h>   // strncpy

typedef struct {
    char accountHolder[50];
    double balance;
} BankAccount;

// "CONSTRUCTOR": Sets up the account with an initial balance
void account_init(BankAccount *acc, const char *name, double initialBalance) {
    strncpy(acc->accountHolder, name, sizeof(acc->accountHolder) - 1);
    acc->accountHolder[sizeof(acc->accountHolder) - 1] = '\0';

    // Only allow a positive initial balance
    if (initialBalance >= 0) {
        acc->balance = initialBalance;
    } else {
        acc->balance = 0;
        printf("Warning: Initial balance cannot be negative. Set to 0.\n");
    }
}

// METHOD: Deposit money
void account_deposit(BankAccount *acc, double amount) {
    // VALIDATION: Check if the deposit is a positive number
    if (amount > 0) {
        acc->balance += amount;
        printf("Successfully deposited: $%g\n", amount);
    } else {
        printf("Error: Deposit amount must be greater than 0.\n");
    }
}

// METHOD: Withdraw money
void account_withdraw(BankAccount *acc, double amount) {
    // VALIDATION 1: Check if amount is positive
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than 0.\n");
        return;   // Exit the function early
    }

    // VALIDATION 2: Check if there are sufficient funds
    if (amount > acc->balance) {
        printf("Error: Insufficient funds! Current balance is $%g\n", acc->balance);
    } else {
        acc->balance -= amount;
        printf("Successfully withdrew: $%g\n", amount);
    }
}

// METHOD: Check balance
void account_displayBalance(const BankAccount *acc) {
    printf("Account Holder: %s\n", acc->accountHolder);
    printf("Current Balance: $%g\n", acc->balance);
}

int main() {
    printf("--- Opening Account ---\n");
    // Create an account for Alice with $500
    BankAccount aliceAccount;
    account_init(&aliceAccount, "Alice Smith", 500.00);
    account_displayBalance(&aliceAccount);

    printf("\n--- Attempting Deposits ---\n");
    account_deposit(&aliceAccount, 200.00);   // Valid
    account_deposit(&aliceAccount, -50.00);   // Invalid (negative)

    printf("\n--- Attempting Withdrawals ---\n");
    account_withdraw(&aliceAccount, 100.00);    // Valid
    account_withdraw(&aliceAccount, 1000.00);   // Invalid (insufficient funds)
    account_withdraw(&aliceAccount, -20.00);    // Invalid (negative)

    printf("\n--- Final Account Status ---\n");
    account_displayBalance(&aliceAccount);

    return 0;
}