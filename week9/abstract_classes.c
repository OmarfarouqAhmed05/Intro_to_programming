// ============================================================
// ACTIVITY 3: ABSTRACT CLASSES (C version)
// Learning Outcome: Evaluate pure virtual functions
//
// NOTE: C has no abstract classes. The Shape "interface" is a struct
// holding a function pointer for calculateArea. Each concrete shape
// (Square, Circle) must fill that pointer in. A generic Shape has no
// function to put there, so it is never created on its own.
// C cannot STOP you from creating one: if the pointer is left NULL and
// you call it, the program crashes at run time. C++ stops it at
// compile time instead.
// ============================================================

#include <stdio.h>

// The abstract "Shape": only the interface (a function pointer)
typedef struct Shape Shape;
struct Shape {
    double (*calculateArea)(Shape *self);   // "pure virtual": children MUST set it
};

// ---------------- Square ----------------
typedef struct {
    Shape base;
    double side;
} Square;

double square_calculateArea(Shape *self) {
    Square *s = (Square *)self;   // safe: base is the first member
    return s->side * s->side;
}

void square_init(Square *s, double side) {
    s->base.calculateArea = square_calculateArea;   // we MUST provide this
    s->side = side;
}

// ---------------- Circle ----------------
typedef struct {
    Shape base;
    double radius;
} Circle;

double circle_calculateArea(Shape *self) {
    Circle *c = (Circle *)self;
    return 3.14159 * c->radius * c->radius;
}

void circle_init(Circle *c, double radius) {
    c->base.calculateArea = circle_calculateArea;   // we MUST provide this too
    c->radius = radius;
}

int main() {
    // A bare "Shape" has no area function, so we never create one by itself.

    Square s;
    Circle c;
    square_init(&s, 5.0);
    circle_init(&c, 3.0);

    printf("Area of Square: %g\n", s.base.calculateArea(&s.base));
    printf("Area of Circle: %g\n", c.base.calculateArea(&c.base));

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 3)
// - A struct of function pointers acts as the abstract interface.
// - Every concrete type must fill the pointers in.
// - C++ refuses to compile an incomplete class; C only fails at run time.
// ------------------------------------------------------------