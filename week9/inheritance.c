// ============================================================
// ACTIVITY 1: BASIC INHERITANCE (C version)
// Learning Outcome: Apply inheritance to model a hierarchy
//
// NOTE: C has no inheritance. We imitate it with COMPOSITION: the
// "child" struct holds the "parent" struct as its FIRST member.
// "Calling the base constructor" = calling shape_init() from inside
// circle_init(). There is no 'protected' in C, so the children simply
// reach into base.color (we treat it as "protected" by convention).
// ============================================================

#include <stdio.h>
#include <string.h>

// ------------------------------------------------------------
// BASE "CLASS" (Parent)
// ------------------------------------------------------------
typedef struct {
    char color[30];   // treated as 'protected'
} Shape;

// Constructor for the base "class"
void shape_init(Shape *s, const char *c) {
    strncpy(s->color, c, sizeof(s->color) - 1);
    s->color[sizeof(s->color) - 1] = '\0';
    printf("Shape constructor called.\n");
}

// A function that all shapes share
void shape_displayColor(const Shape *s) {
    printf("This shape's color is: %s\n", s->color);
}

// ------------------------------------------------------------
// DERIVED "CLASS" (Child): Circle IS-A Shape, so Shape comes FIRST
// ------------------------------------------------------------
typedef struct {
    Shape base;      // the inherited part
    double radius;
} Circle;

// Constructor: Must call the base constructor first
void circle_init(Circle *c, const char *color, double r) {
    shape_init(&c->base, color);
    c->radius = r;
    printf("Circle constructor called.\n");
}

void circle_displayInfo(const Circle *c) {
    // We can use base.color here (our "protected" member)
    printf("This circle is %s and has a radius of %g\n", c->base.color, c->radius);
}

// Another derived "class"
typedef struct {
    Shape base;
    double width, height;
} Rectangle;

void rectangle_init(Rectangle *r, const char *color, double w, double h) {
    shape_init(&r->base, color);
    r->width = w;
    r->height = h;
    printf("Rectangle constructor called.\n");
}

void rectangle_displayInfo(const Rectangle *r) {
    printf("This rectangle is %s and is %gx%g\n", r->base.color, r->width, r->height);
}

int main() {
    printf("--- Creating a Circle ---\n");
    Circle myCircle;
    circle_init(&myCircle, "Red", 5.0);
    shape_displayColor(&myCircle.base);   // Inherited function from Shape
    circle_displayInfo(&myCircle);        // Unique function from Circle

    printf("\n--- Creating a Rectangle ---\n");
    Rectangle myRect;
    rectangle_init(&myRect, "Blue", 4.0, 6.0);
    shape_displayColor(&myRect.base);     // Inherited function from Shape
    rectangle_displayInfo(&myRect);       // Unique function from Rectangle

    return 0;
}

// ------------------------------------------------------------
// LESSONS LEARNED (Activity 1)
// - Composition with the parent as the first member imitates inheritance.
// - The base constructor is called first, then the child's own setup.
// - C cannot enforce 'protected': it is only a convention.
// ------------------------------------------------------------