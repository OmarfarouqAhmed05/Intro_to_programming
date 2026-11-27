// ============================================================
// ACTIVITY 2: IGNORING FILE ERRORS
// Learning Outcome: Analyse unhandled file errors
// ============================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // We are trying to open a file called "missing_file.txt" which DOES NOT EXIST.
    ifstream myFile("missing_file.txt");

    // WE ARE SKIPPING THE is_open() CHECK!
    // Let's see what happens.

    string data;

    cout << "Attempting to read from missing file..." << endl;

    // Attempting to read from a failed stream
    myFile >> data;

    // What will print here? Will the program crash? Will it print garbage?
    cout << "Data read: " << data << endl;
    cout << "Program continued running without crashing." << endl;

    return 0;
}

// ------------------------------------------------------------
// ANALYSIS QUESTIONS (write these in your notebook)
// 1. Did the program crash?
//    No. C++ usually fails silently with file streams.
// 2. What printed for data?
//    Nothing was printed, because data remained empty.
// 3. Why is this dangerous?
//    The program keeps running with empty or corrupted data. In a banking
//    app the balance would be calculated as 0, causing a massive error.
//
// LESSONS LEARNED (Activity 2)
// - C++ file streams do not crash automatically if a file is missing.
// - Without is_open(), the program reads nothing and carries on.
// - This "silent failure" can corrupt data later in the program.
// ------------------------------------------------------------