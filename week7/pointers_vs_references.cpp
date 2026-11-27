#include <iostream>
using namespace std;

int main() {
    int originalValue = 100;

    // Reference: an alias for originalValue
    int& refValue = originalValue;

    // Pointer: holds the address of originalValue
    int* ptrValue = &originalValue;

    cout << "--- Initial State ---" << endl;
    cout << "originalValue: " << originalValue << endl;
    cout << "refValue: " << refValue << endl;
    cout << "ptrValue points to: " << *ptrValue << endl;

    // Modification 1: via reference
    refValue = 200;

    cout << "\n--- After setting refValue = 200 ---" << endl;
    cout << "originalValue: " << originalValue << endl;
    cout << "ptrValue points to: " << *ptrValue << endl;

    // Modification 2: via pointer
    *ptrValue = 300;

    cout << "\n--- After setting *ptrValue = 300 ---" << endl;
    cout << "originalValue: " << originalValue << endl;
    cout << "refValue: " << refValue << endl;

    // Modification 3: re-point the pointer
    int anotherValue = 500;
    ptrValue = &anotherValue;

    cout << "\n--- After pointing ptrValue to anotherValue ---" << endl;
    cout << "originalValue: " << originalValue << endl;
    cout << "ptrValue points to: " << *ptrValue << endl;

    // A reference cannot be re-seated:
    // refValue = anotherValue; would just copy 500 into originalValue.

    return 0;
}