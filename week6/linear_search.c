// ============================================================
// ACTIVITY 1: LINEAR SEARCH IN AN INTEGER ARRAY (C version)
// File: linear_search.c
// Learning Outcome: Apply linear search to find an element in an integer array
// ============================================================

// Include the standard input/output library
#include <stdio.h>

// ------------------------------------------------------------
// FUNCTION: linearSearch
// Purpose: Search for a target value in an array
// Parameters: arr (the array), size (number of elements), target (value to find)
// Returns: index of the target if found, -1 if not found
// ------------------------------------------------------------
int linearSearch(int arr[], int size, int target) {
    // Loop through each element in the array
    for (int i = 0; i < size; i++) {
        // Compare the current element with the target
        if (arr[i] == target) {
            // If a match is found, return the index immediately
            return i;
        }
    }
    // If the loop finishes without finding the target, return -1
    return -1;
}

// The main function
int main() {
    // Declare and initialise an array of 8 integers
    int numbers[8] = {15, 42, 7, 89, 23, 56, 11, 74};

    // Store the size of the array in a variable
    // sizeof(numbers) / sizeof(numbers[0]) gives the number of elements
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Declare a variable to store the user's target value
    int target;

    // Display the array contents so the user knows what is inside
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Ask the user to enter a number to search for
    printf("Enter a number to search: ");

    // scanf returns 1 when it read one number successfully
    if (scanf("%d", &target) != 1) {
        printf("Invalid input. Please enter a whole number.\n");
        return 1;
    }

    // Call the linearSearch function and store the result
    int position = linearSearch(numbers, size, target);

    // Check if the element was found (position != -1 means found)
    if (position != -1) {
        // Display the position (index) where the element was found
        printf("Element found at index: %d\n", position);
    } else {
        // Display a message if the element was not found
        printf("Element not found in the array.\n");
    }

    return 0;
}

// ------------------------------------------------------------
// STEP 4: TEST WITH THESE INPUTS
//   42  -> Element found at index: 1
//   74  -> Element found at index: 7
//   100 -> Element not found in the array.
//
// STEP 5: TRACE THE SEARCH (target = 89)
//   i | arr[i] | arr[i] == 89? | Action
//   0 |   15   | No            | Continue
//   1 |   42   | No            | Continue
//   2 |    7   | No            | Continue
//   3 |   89   | Yes           | Return 3
//   Output: Element found at index: 3
// ------------------------------------------------------------