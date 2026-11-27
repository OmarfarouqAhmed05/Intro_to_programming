#include <iostream>
using namespace std;

// 3A: allocates memory but never frees it (LEAK)
void createLeak() {
    int* ptr = new int(42);

    cout << "Inside function. The value is: " << *ptr << endl;
    cout << "Memory allocated at address: " << ptr << endl;

    // ptr is destroyed here, but the heap memory is never freed
}

// 3B: the fix, using delete
void fixLeak() {
    int* ptr = new int(42);

    cout << "Inside fixed function. Value: " << *ptr << endl;
    cout << "Memory allocated at address: " << ptr << endl;

    delete ptr;      // free the memory
    ptr = nullptr;   // avoid a dangling pointer

    cout << "Memory has been successfully freed." << endl;
}

int main() {
    cout << "--- Demonstrating the Leak ---" << endl;
    cout << "Calling function that leaks memory..." << endl;
    createLeak();
    cout << "Function finished. The memory is now leaked." << endl;

    cout << "\n--- Testing the Fix ---" << endl;
    fixLeak();

    return 0;
}