// ============================================================
// ACTIVITY 3B: THE "std::string" IDEA IN C (C version)
// File: dynamic_string.c
// Learning Outcome: Evaluate the advantages and disadvantages of C-strings vs std::string
//
// NOTE: C has NO std::string. This program shows the manual equivalent:
// a string stored on the heap that grows as needed. In C++ the
// std::string class does all of this work for you automatically.
// ============================================================

#include <stdio.h>
#include <stdlib.h>   // malloc, realloc, free
#include <string.h>   // strlen, strcpy, strcmp

// ------------------------------------------------------------
// FUNCTION: readLineDynamic
// Purpose: Read a whole line of ANY length (the buffer grows when full)
// Returns: a heap string that the caller must free(), or NULL on error
// ------------------------------------------------------------
char *readLineDynamic(void) {
    size_t capacity = 16;   // start small
    size_t length = 0;      // characters stored so far
    char *buffer = malloc(capacity);
    if (buffer == NULL) {
        return NULL;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Leave room for the new character and the final '\0'
        if (length + 1 >= capacity) {
            capacity *= 2;                       // double the capacity
            char *bigger = realloc(buffer, capacity);
            if (bigger == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = bigger;
        }
        buffer[length++] = (char)ch;
    }
    buffer[length] = '\0';   // end-of-text marker
    return buffer;
}

int main() {
    // Ask the user to enter their name
    printf("Enter your name: ");
    char *name = readLineDynamic();
    if (name == NULL) {
        printf("Out of memory.\n");
        return 1;
    }

    // Display the name
    printf("Name: %s\n", name);

    // Length (like name.length())
    printf("Length: %zu\n", strlen(name));

    // First character (like name[0])
    printf("First character: %c\n", name[0]);

    // Copy: we must allocate memory ourselves (std::string does this with =)
    char *copy = malloc(strlen(name) + 1);   // +1 for the '\0'
    if (copy == NULL) {
        free(name);
        return 1;
    }
    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    // Concatenate: allocate exactly the size we need (like "Hello, " + name + "!")
    size_t greetingSize = strlen("Hello, ") + strlen(name) + strlen("!") + 1;
    char *greeting = malloc(greetingSize);
    if (greeting == NULL) {
        free(name);
        free(copy);
        return 1;
    }
    snprintf(greeting, greetingSize, "Hello, %s!", name);
    printf("%s\n", greeting);

    // Compare with strcmp (std::string uses ==)
    printf("Copy equals original: %s\n", strcmp(copy, name) == 0 ? "Yes" : "No");

    // We MUST free every block we allocated (std::string frees itself)
    free(name);
    free(copy);
    free(greeting);

    return 0;
}