#include <iostream>
#include <string>
using namespace std;

int main() {

    // VARIABLE DECLARATIONS
    string name;
    string course;
    string hobby;
    string reason;
    string expectation;
    string definition;

    // WELCOME MESSAGE
    cout << "========================================" << endl;
    cout << "   WELCOME TO YOUR FIRST PROGRAM!" << endl;
    cout << "========================================" << endl;
    cout << endl;

    // QUESTIONS
    cout << "1. What is your name? ";
    getline(cin, name);

    cout << "2. What course are you doing? (BBIT/BCS): ";
    getline(cin, course);

    cout << "3. What is your hobby? ";
    getline(cin, hobby);

    cout << "4. Why did you choose this course? ";
    getline(cin, reason);

    cout << "5. What do you expect to learn in programming? ";
    getline(cin, expectation);

    cout << "6. In your own words, what is programming? ";
    getline(cin, definition);

    // DISPLAY SUMMARY
    cout << endl;
    cout << "========================================" << endl;
    cout << "        YOUR PROFILE SUMMARY" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Name: " << name << endl;
    cout << "Course: " << course << endl;
    cout << "Hobby: " << hobby << endl;
    cout << "Reason: " << reason << endl;
    cout << "Expectation: " << expectation << endl;
    cout << "Programming is: " << definition << endl;
    cout << endl;

    cout << "========================================" << endl;
    cout << "     Thank you for completing this!" << endl;
    cout << "========================================" << endl;

    return 0;
}

// #include <iostream>
// using namespace std;
// int main(){

// // ============================================================
// //VARIABLE DECLARATIONS

// string name;
// string course;
// string hobby;
// string reason;
// string expectation;
// string definition;

// // ============================================================
// // QUESTION 1: NAME
// // ============================================================

// cout << "========================================" << endl;
// cout << " WELCOME TO YOUR FIRST PROGRAM!" << endl;
// cout << "========================================" << endl;
// cout << endl;

// cout <<"What is your name? ";
// getline(cin, name);


// return 0;

// }
