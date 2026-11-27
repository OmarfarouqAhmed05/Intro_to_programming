// ============================================================
// ACTIVITY 4: DYNAMIC ARRAY WRAPPER (MINI-VECTOR) (C version)
// File: dynamic_array.c
// Learning Outcome: Create a dynamic array that resizes itself when full
//
// NOTE: C has no classes, constructors or destructors. We use a struct
// plus functions. We must call da_init() ourselves at the start and
// da_free() ourselves at the end (C++ does both automatically).
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // malloc and free

// A struct groups the pointer, size, and capacity together
typedef struct {
    int *data;      // Pointer to the dynamically allocated array
    int size;       // Number of actual elements currently stored
    int capacity;   // Total number of slots currently allocated
} DynamicArray;

// "CONSTRUCTOR": sets up the array with an initial capacity
// Returns 1 on success, 0 if memory could not be allocated
int da_init(DynamicArray *arr, int initialCapacity) {
    arr->capacity = initialCapacity;
    arr->size = 0;
    // Allocate the initial raw array on the heap
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
    return arr->data != NULL;
}

// "DESTRUCTOR": cleans up the dynamic memory to prevent leaks!
void da_free(DynamicArray *arr) {
    free(arr->data);
    arr->data = NULL;   // avoid a dangling pointer
    arr->size = 0;
    arr->capacity = 0;
}

// Function to add a new element to the end
// Returns 1 on success, 0 if resizing failed
int da_push_back(DynamicArray *arr, int value) {
    // 1. Check if we have run out of space
    if (arr->size == arr->capacity) {
        // We need to resize!
        // a. Double the capacity
        int newCapacity = arr->capacity * 2;

        // b. Allocate a new, larger array on the heap
        int *newData = (int *)malloc(newCapacity * sizeof(int));
        if (newData == NULL) {
            return 0;   // keep the old array untouched
        }

        // c. Copy the old elements into the new array
        for (int i = 0; i < arr->size; i++) {
            newData[i] = arr->data[i];
        }

        // d. Free the old, smaller array to release memory
        free(arr->data);

        // e. Update our pointer and capacity to use the new array
        arr->data = newData;
        arr->capacity = newCapacity;

        printf("[Resized capacity from %d to %d]\n", arr->capacity / 2, arr->capacity);
    }

    // 2. Add the new value at the next available slot
    arr->data[arr->size] = value;
    arr->size++;   // Increment the size counter
    return 1;
}

// Function to print the array contents
void da_display(const DynamicArray *arr) {
    printf("Array (Size: %d, Capacity: %d): ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    // Create a dynamic array starting with a capacity of 2
    DynamicArray myArray;
    if (!da_init(&myArray, 2)) {
        printf("Out of memory.\n");
        return 1;
    }
    printf("Created dynamic array with capacity 2.\n");

    // Add elements and watch it resize automatically
    da_push_back(&myArray, 10);
    da_push_back(&myArray, 20);
    da_display(&myArray);

    // This push_back should trigger a resize!
    printf("\nAdding third element...\n");
    da_push_back(&myArray, 30);
    da_display(&myArray);

    printf("\nAdding fourth and fifth elements...\n");
    da_push_back(&myArray, 40);
    da_push_back(&myArray, 50);   // This will trigger another resize
    da_display(&myArray);

    // In C we must free the memory ourselves, otherwise it leaks.
    da_free(&myArray);

    return 0;
}