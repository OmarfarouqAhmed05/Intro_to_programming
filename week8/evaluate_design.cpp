// ============================================================
// ACTIVITY 3: EVALUATING CLASS DESIGN
// Learning Outcome: Evaluate encapsulation violations
// ============================================================

#include <iostream>
using namespace std;

// ==========================================
// THE BAD DESIGN (Violation of Encapsulation)
// ==========================================
class BadBankAccount {
public:
    // Everything is public! Anyone can change the balance directly.
    double balance;

    BadBankAccount() {
        balance = 0.0;
    }
};

// ==========================================
// THE GOOD DESIGN (Proper Encapsulation)
// ==========================================
class GoodBankAccount {
private:
    // Data is hidden. It can only be changed through methods.
    double balance;

public:
    GoodBankAccount() {
        balance = 0.0;
    }

    void deposit(double amount) {
        // The method checks the rule before changing the balance
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    cout << "--- Testing BAD Design ---" << endl;
    BadBankAccount badAccount;
    // Direct access! No validation. We can hack the account.
    badAccount.balance = -5000;   // Impossible in real life!
    cout << "Bad Account Balance: " << badAccount.balance << endl;

    cout << "\n--- Testing GOOD Design ---" << endl;
    GoodBankAccount goodAccount;

    // goodAccount.balance = -5000;   // ERROR! Private! The compiler will block this!
    // We must use the safe method.
    goodAccount.deposit(1000);
    cout << "Good Account Balance: " << goodAccount.getBalance() << endl;

    // Extra: the safe method also rejects a negative deposit
    goodAccount.deposit(-300);
    cout << "Balance after trying to deposit -300: " << goodAccount.getBalance() << endl;

    return 0;
}

// ------------------------------------------------------------
// STEP 3: EVALUATE AND ANSWER
// 1. Why is BadBankAccount dangerous?
//    Because any part of the program can modify balance without
//    validation, leading to impossible states like a negative balance.
// 2. How does GoodBankAccount prevent this?
//    By making balance private. The only way to change it is through the
//    deposit method, which has a built-in check: if (amount > 0).
// ------------------------------------------------------------