// ============================================================
// ACTIVITY 4: GEOMETRY FUNCTION LIBRARY (C version)
// File: geometry_library.c
// Learning Outcome: Create and use a library of functions
// Includes all four challenges:
//   1. areaOfSquare            2. perimeterOfRectangle
//   3. input validation        4. "Calculate all" menu option
// ============================================================

#include <stdio.h>
#include <math.h>    // For pow()

// ------------------------------------------------------------
// CONSTANT: PI
// Global constant for the value of pi
// ------------------------------------------------------------
const double PI = 3.14159;

// Throws away everything left on the current input line.
void clearInputLine(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // keep reading until the end of the line
    }
}

// ------------------------------------------------------------
// FUNCTION: areaOfCircle
// Purpose: Calculate the area of a circle
// Formula: A = pi x r^2
// Parameters: radius (double)
// Returns: area (double)
// ------------------------------------------------------------
double areaOfCircle(double radius) {
    // Check for invalid input
    if (radius < 0) {
        printf("Error: Radius cannot be negative.\n");
        return 0.0;
    }

    // Calculate and return the area (pow(radius, 2) is radius squared)
    return PI * pow(radius, 2);
}

// ------------------------------------------------------------
// FUNCTION: areaOfRectangle
// Purpose: Calculate the area of a rectangle
// Formula: A = length x width
// Parameters: length and width (double)
// Returns: area (double)
// ------------------------------------------------------------
double areaOfRectangle(double length, double width) {
    // Check for invalid input
    if (length < 0 || width < 0) {
        printf("Error: Length and width cannot be negative.\n");
        return 0.0;
    }

    // Calculate and return the area
    return length * width;
}

// ------------------------------------------------------------
// FUNCTION: areaOfTriangle
// Purpose: Calculate the area of a triangle
// Formula: A = 1/2 x base x height
// Parameters: base and height (double)
// Returns: area (double)
// ------------------------------------------------------------
double areaOfTriangle(double base, double height) {
    // Check for invalid input
    if (base < 0 || height < 0) {
        printf("Error: Base and height cannot be negative.\n");
        return 0.0;
    }

    // Calculate and return the area
    return 0.5 * base * height;
}

// ------------------------------------------------------------
// FUNCTION: areaOfSquare (Challenge 1)
// Purpose: Calculate the area of a square
// Formula: A = side x side
// Parameters: side (double)
// Returns: area (double)
// ------------------------------------------------------------
double areaOfSquare(double side) {
    // Check for invalid input
    if (side < 0) {
        printf("Error: Side cannot be negative.\n");
        return 0.0;
    }

    // Calculate and return the area
    return side * side;
}

// ------------------------------------------------------------
// FUNCTION: perimeterOfRectangle (Challenge 2)
// Purpose: Calculate the perimeter of a rectangle
// Formula: P = 2 x (length + width)
// Parameters: length and width (double)
// Returns: perimeter (double)
// ------------------------------------------------------------
double perimeterOfRectangle(double length, double width) {
    // Check for invalid input
    if (length < 0 || width < 0) {
        printf("Error: Length and width cannot be negative.\n");
        return 0.0;
    }

    // Calculate and return the perimeter
    return 2 * (length + width);
}

// ------------------------------------------------------------
// FUNCTION: readPositive (Challenge 3: input validation)
// Purpose: Asks for a number and keeps asking until the user
//          enters a number that is not negative.
// Parameters: prompt (the text to show the user)
// Returns: the valid number (double)
// ------------------------------------------------------------
double readPositive(const char *prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        // scanf returns 1 when it read one number successfully
        if (scanf("%lf", &value) != 1) {
            clearInputLine();
            printf("Invalid input. Please enter a number.\n");
        } else if (value < 0) {
            clearInputLine();
            printf("Error: the number cannot be negative.\n");
        } else {
            clearInputLine();
            return value;
        }
    }
}

// ------------------------------------------------------------
// FUNCTION: displayMenu
// Purpose: Display the menu options
// ------------------------------------------------------------
void displayMenu() {
    printf("\n===== GEOMETRY CALCULATOR =====\n");
    printf("1. Area of Circle\n");
    printf("2. Area of Rectangle\n");
    printf("3. Area of Triangle\n");
    printf("4. Area of Square\n");
    printf("5. Perimeter of Rectangle\n");
    printf("6. Calculate all\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// The main function
int main() {
    int choice;
    double radius, length, width, base, height, side, area;

    // Loop until the user chooses to exit
    do {
        // Display the menu
        displayMenu();

        // If the user typed letters instead of a number, treat it as invalid
        if (scanf("%d", &choice) != 1) {
            choice = 0;
        }
        clearInputLine();

        // Process the user's choice (%.2f prints 2 decimal places)
        switch (choice) {
            case 1:
                radius = readPositive("Enter radius: ");
                area = areaOfCircle(radius);
                printf("Area of circle: %.2f\n", area);
                break;

            case 2:
                length = readPositive("Enter length: ");
                width = readPositive("Enter width: ");
                area = areaOfRectangle(length, width);
                printf("Area of rectangle: %.2f\n", area);
                break;

            case 3:
                base = readPositive("Enter base: ");
                height = readPositive("Enter height: ");
                area = areaOfTriangle(base, height);
                printf("Area of triangle: %.2f\n", area);
                break;

            case 4:
                side = readPositive("Enter side: ");
                area = areaOfSquare(side);
                printf("Area of square: %.2f\n", area);
                break;

            case 5:
                length = readPositive("Enter length: ");
                width = readPositive("Enter width: ");
                printf("Perimeter of rectangle: %.2f\n",
                       perimeterOfRectangle(length, width));
                break;

            case 6:
                // Challenge 4: ask for every measurement once, then show all results
                radius = readPositive("Enter radius (circle): ");
                length = readPositive("Enter length (rectangle): ");
                width = readPositive("Enter width (rectangle): ");
                base = readPositive("Enter base (triangle): ");
                height = readPositive("Enter height (triangle): ");
                side = readPositive("Enter side (square): ");

                printf("\n--- All results ---\n");
                printf("Area of circle:           %.2f\n", areaOfCircle(radius));
                printf("Area of rectangle:        %.2f\n", areaOfRectangle(length, width));
                printf("Area of triangle:         %.2f\n", areaOfTriangle(base, height));
                printf("Area of square:           %.2f\n", areaOfSquare(side));
                printf("Perimeter of rectangle:   %.2f\n", perimeterOfRectangle(length, width));
                break;

            case 7:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}