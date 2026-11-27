// ============================================================
// ACTIVITY 3: RETURN CODES VS EXCEPTIONS
// Learning Outcome: Evaluate exception handling strategies
// Note: data.txt does NOT exist on purpose, so both methods hit the error.
// ============================================================

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>   // Required for standard exceptions
using namespace std;

// METHOD 1: Using Return Codes (The old C way)
// Returns true if successful, false if failed.
bool readFileWithReturnCode(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // We must manually pass the error back up
        return false;
    }
    // ... read file ...
    return true;
}

// METHOD 2: Using Exceptions (The modern C++ way)
void readFileWithException(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // We actively THROW an error. The program will immediately stop
        // looking for the file and jump to the catch block.
        throw runtime_error("File not found: " + filename);
    }
    // ... read file ...
}

int main() {
    cout << "--- Testing Return Code Strategy ---" << endl;
    if (readFileWithReturnCode("data.txt") == false) {
        cout << "Return Code: Handled error gracefully. Program continues." << endl;
    }

    cout << "\n--- Testing Exception Strategy ---" << endl;
    // We put the dangerous code in a 'try' block
    try {
        readFileWithException("data.txt");
    }
    // If an exception is thrown, the 'catch' block handles it.
    catch (const runtime_error& e) {
        cout << "Exception Caught: " << e.what() << endl;
        cout << "Exception Strategy: Forced us to handle the error!" << endl;
    }

    return 0;
}

// ------------------------------------------------------------
// EVALUATE THE STRATEGIES
// 1. Return codes: good for simple, expected errors, but programmers
//    often forget to check the return value, which leads to bugs.
// 2. Exceptions: better for critical errors (like missing files). If the
//    programmer forgets try-catch the program crashes, forcing them to fix
//    the code before release. This is why modern C++ prefers exceptions.
//
// LESSONS LEARNED (Activity 3)
// - try tests dangerous code, throw raises the error, catch handles it.
// - An exception that is thrown but not caught terminates the program.
// ------------------------------------------------------------