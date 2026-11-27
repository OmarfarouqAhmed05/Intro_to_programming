// ============================================================
// ACTIVITY 2: VIRTUAL FUNCTIONS
// Learning Outcome: Analyse dynamic binding
//
// The handout runs the program TWICE: first WITHOUT 'virtual', then with
// the fix. To show both results in one run, this file has two pairs of
// classes: Animal/Dog (no virtual) and VAnimal/VDog (with virtual).
// ============================================================

#include <iostream>
using namespace std;

// ---------------- PART 1: WITHOUT virtual ----------------

// Base class
class Animal {
public:
    // NOTE: We are NOT using the 'virtual' keyword here yet!
    void speak() {
        cout << "Animal makes a generic sound." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    // This hides the base class method (it is not a true override)
    void speak() {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

// ---------------- PART 2: THE FIX (with virtual) ----------------

class VAnimal {
public:
    // THE FIX: Add 'virtual' here
    virtual void speak() {
        cout << "Animal makes a generic sound." << endl;
    }

    // A virtual destructor so deleting through a base pointer is safe
    virtual ~VAnimal() {}
};

class VDog : public VAnimal {
public:
    void speak() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
};

int main() {
    cout << "--- Without Virtual Keyword ---" << endl;
    // We create a POINTER of type Animal (Base)
    Animal* myPet;

    // We point it to a Dog object (Derived)
    myPet = new Dog();

    // We call speak().
    // What do you expect to happen?
    myPet->speak();   // <--- ANALYZE THIS LINE (prints the ANIMAL version)

    delete myPet;

    cout << "\n--- With Virtual Keyword (the fix) ---" << endl;
    VAnimal* myPet2 = new VDog();
    myPet2->speak();   // prints the DOG version

    delete myPet2;

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 2)
// - Static binding: by default the compiler picks the function from the
//   POINTER type (Animal*), so the Animal version runs.
// - Dynamic binding: 'virtual' makes the program check the ACTUAL object
//   (Dog) at run time and call the correct function.
// ------------------------------------------------------------