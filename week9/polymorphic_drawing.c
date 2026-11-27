// ============================================================
// ACTIVITY 4: POLYMORPHIC DRAWING PROGRAM (C version)
// Learning Outcome: Create a polymorphic application
//
// NOTE: C has no virtual functions, vector or 'new'. We use:
//   - a struct of function pointers as the "virtual" draw()
//   - a fixed-size array of Shape* instead of vector<Shape*>
//   - malloc / free instead of new / delete
// (free() needs no "virtual destructor" because every shape is a single
//  malloc block that starts at the Shape part.)
// ============================================================

#include <stdio.h>
#include <stdlib.h>

#define MAX_SHAPES 10

// 1. ABSTRACT BASE "CLASS"
typedef struct Shape Shape;
struct Shape {
    void (*draw)(Shape *self);   // every shape MUST set this
};

// 2. DERIVED "CLASSES"
typedef struct { Shape base; } Circle;
typedef struct { Shape base; } Rectangle;
typedef struct { Shape base; } Triangle;

void circle_draw(Shape *self)    { (void)self; printf("Drawing a Circle ◯\n"); }
void rectangle_draw(Shape *self) { (void)self; printf("Drawing a Rectangle ▭\n"); }
void triangle_draw(Shape *self)  { (void)self; printf("Drawing a Triangle △\n"); }

// "Constructors" that allocate on the heap and return a Shape*
Shape *circle_new(void) {
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (!c) exit(1);
    c->base.draw = circle_draw;
    return &c->base;
}
Shape *rectangle_new(void) {
    Rectangle *r = (Rectangle *)malloc(sizeof(Rectangle));
    if (!r) exit(1);
    r->base.draw = rectangle_draw;
    return &r->base;
}
Shape *triangle_new(void) {
    Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    if (!t) exit(1);
    t->base.draw = triangle_draw;
    return &t->base;
}

// 3. A POLYMORPHIC FUNCTION
// This function doesn't care WHAT the shape is. It just knows it's a Shape.
void renderCanvas(Shape *s) {
    s->draw(s);   // the function pointer decides which draw() runs
}

int main() {
    // A fixed array of Shape pointers replaces the vector
    Shape *canvas[MAX_SHAPES];
    int count = 0;

    // We add different "derived" objects to the array
    canvas[count++] = circle_new();
    canvas[count++] = rectangle_new();
    canvas[count++] = triangle_new();
    canvas[count++] = circle_new();

    printf("--- Rendering Canvas ---\n");
    // Loop through the canvas and draw everything
    for (int i = 0; i < count; i++) {
        renderCanvas(canvas[i]);
    }

    printf("\n--- Cleaning Up Memory ---\n");
    // Clean up the heap memory
    for (int i = 0; i < count; i++) {
        free(canvas[i]);
        canvas[i] = NULL;
    }

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 4)
// - An array of Shape* can hold different "derived" objects.
// - Calling through the stored function pointer runs the version for
//   the ACTUAL object (dynamic binding, done by hand).
// - Every malloc needs a free.
// ------------------------------------------------------------