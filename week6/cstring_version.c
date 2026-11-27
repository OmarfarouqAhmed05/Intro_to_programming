// ============================================================
// ACTIVITY 3A: C-STRING VERSION (C version)
// File: cstring_version.c
// Learning Outcome: Evaluate the advantages and disadvantages of C-strings vs std::string
// ============================================================

#include <stdio.h>
#include <string.h>   // For strlen, strcpy, strcat, strcmp, strcspn

int main() {
    // Declare a C-string (character array) with a maximum size
    // 50 characters = up to 49 letters + 1 end-of-text marker ('\0')
    char name[50];

    // Ask the user to enter their name
    printf("Enter your name: ");

    // fgets reads a full line (never more than 49 characters) into the C-string
    // It is the C equivalent of cin.getline(name, 50)
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("No input received.\n");
        return 1;
    }

    // fgets keeps the newline at the end, so we replace it with '\0'
    name[strcspn(name, "\n")] = '\0';

    // Display the name
    printf("Name: %s\n", name);

    // Use strlen to find the length of the C-string
    printf("Length: %zu\n", strlen(name));

    // Display the first character
    printf("First character: %c\n", name[0]);

    // Copy the C-string to another C-string using strcpy
    // The destination must be big enough, otherwise we get a buffer overflow
    char copy[50];
    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    // Extra (from the evaluation table): concatenate with strcpy + strcat
    // The buffer is large enough: "Hello, " (7) + name (max 49) + "!" (1) + '\0' = 58
    char greeting[100];
    strcpy(greeting, "Hello, ");
    strcat(greeting, name);
    strcat(greeting, "!");
    printf("%s\n", greeting);

    // Extra (from the evaluation table): compare with strcmp
    // strcmp returns 0 when the two C-strings are equal
    printf("Copy equals original: %s\n", strcmp(copy, name) == 0 ? "Yes" : "No");

    return 0;
}