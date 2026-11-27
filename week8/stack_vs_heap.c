// ============================================================
// ACTIVITY 2: STACK VS HEAP OBJECTS (C version)
// File: stack_vs_heap.c
// Learning Outcome: Analyse stack vs heap allocation
//
// NOTE: C has no destructors. In C++ the Toyota's destructor runs
// by itself at the end of main. In C we have to call car_destroy()
// ourselves for BOTH cars, and use malloc/free for the heap car.
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // malloc and free
#include <string.h>   // strncpy

typedef struct {
    char model[50];
} Car;

// "Constructor": fills in the car and prints a message
void car_create(Car *c, const char *m) {
    strncpy(c->model, m, sizeof(c->model) - 1);
    c->model[sizeof(c->model) - 1] = '\0';
    printf("Car created: %s\n", c->model);
}

// "Destructor": we must call this ourselves
void car_destroy(Car *c) {
    printf("Car destroyed: %s\n", c->model);
}

int main() {
    printf("--- Creating Stack Object ---\n");
    // STACK ALLOCATION: Memory is managed automatically.
    // Note: No malloc. The memory vanishes when main ends.
    Car stackCar;
    car_create(&stackCar, "Toyota");

    printf("\n--- Creating Heap Object ---\n");
    // HEAP ALLOCATION: Memory is managed manually using malloc.
    // Note: We use a pointer (*) to hold the memory address.
    Car *heapCar = (Car *)malloc(sizeof(Car));
    if (heapCar == NULL) {
        printf("Out of memory.\n");
        return 1;
    }
    car_create(heapCar, "Honda");

    // To access the heap object's members, we use the arrow operator (->)
    printf("Heap car model: %s\n", heapCar->model);

    // To access the stack object's members, we use the dot operator (.)
    printf("Stack car model: %s\n", stackCar.model);

    printf("\n--- End of main function ---\n");

    // We MUST manually free the heap object to avoid a memory leak.
    car_destroy(heapCar);
    free(heapCar);
    heapCar = NULL;

    // In C++ the Toyota is destroyed AUTOMATICALLY here.
    // In C we have to do it ourselves.
    car_destroy(&stackCar);

    return 0;
}