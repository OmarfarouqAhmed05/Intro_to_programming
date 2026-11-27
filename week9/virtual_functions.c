// ============================================================
// ACTIVITY 2: VIRTUAL FUNCTIONS (C version)
// Learning Outcome: Analyse dynamic binding
//
// NOTE: C has no 'virtual'. Two situations:
//   PART 1 (no virtual): a normal function call. The function is chosen
//          from the TYPE of the pointer we call it through (static binding).
//   PART 2 (the fix):    a FUNCTION POINTER stored inside the object. The
//          call goes to whatever function the object holds (dynamic binding).
// ============================================================

#include <stdio.h>
#include <stdlib.h>

// ---------------- PART 1: WITHOUT virtual ----------------

typedef struct { int dummy; } Animal;           // base
typedef struct { Animal base; } Dog;            // derived: base is first

void animal_speak(Animal *a) {
    (void)a;
    printf("Animal makes a generic sound.\n");
}

void dog_speak(Dog *d) {
    (void)d;
    printf("Dog barks: Woof! Woof!\n");
}

// ---------------- PART 2: THE FIX (function pointer) ----------------

typedef struct VAnimal VAnimal;
struct VAnimal {
    void (*speak)(VAnimal *self);   // plays the role of 'virtual speak()'
};

typedef struct { VAnimal base; } VDog;

void vanimal_speak(VAnimal *self) {
    (void)self;
    printf("Animal makes a generic sound.\n");
}

void vdog_speak(VAnimal *self) {
    (void)self;
    printf("Dog barks: Woof! Woof!\n");
}

int main() {
    printf("--- Without Virtual Keyword ---\n");
    // We make a Dog, but keep it through an Animal pointer
    Dog *dog = (Dog *)malloc(sizeof(Dog));
    Animal *myPet = &dog->base;

    // The call is decided by the pointer TYPE (Animal*): the Animal version
    animal_speak(myPet);   // <--- ANALYZE THIS LINE

    free(dog);

    printf("\n--- With Virtual (function pointer) ---\n");
    VDog *vdog = (VDog *)malloc(sizeof(VDog));
    vdog->base.speak = vdog_speak;     // this object stores the Dog version
    VAnimal *myPet2 = &vdog->base;

    // The call goes through the pointer stored in the object: the Dog version
    myPet2->speak(myPet2);

    free(vdog);

    // vanimal_speak is the base version; an Animal object would store it.
    (void)vanimal_speak;
    (void)dog_speak;
    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 2)
// - A normal call is fixed at compile time (static binding).
// - A call through a function pointer is decided at run time (dynamic
//   binding). This is exactly what C++ does for you with 'virtual'.
// ------------------------------------------------------------