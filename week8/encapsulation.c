// ============================================================
// ACTIVITY 1: ENCAPSULATION & ACCESS SPECIFIERS (C version)
// File: encapsulation.c
// Learning Outcome: Apply encapsulation with getters/setters
//
// NOTE: C has no classes and no 'private' keyword. We get the same
// IDEA by putting the data in a struct and ONLY touching it through
// functions (getters/setters). The compiler cannot stop someone from
// writing s1.age = 30 directly, so in C this is a rule we follow.
// (Real C projects hide the struct inside a .c file and only show a
// pointer in the .h file, which makes the fields truly private.)
// ============================================================

#include <stdio.h>
#include <string.h>   // strncpy

// The "class": a struct holding the data
typedef struct {
    char name[50];   // treat as PRIVATE: use the functions below
    int age;         // treat as PRIVATE: use the functions below
} Student;

// SETTER (Mutator): safely MODIFY the 'age' data.
void student_setAge(Student *s, int newAge) {
    // VALIDATION: We only allow the age to change if it makes sense.
    if (newAge > 0 && newAge < 120) {
        s->age = newAge;
    } else {
        printf("Error: Invalid age! Age must be between 1 and 119.\n");
        // If invalid, we set a default value of 0
        s->age = 0;
    }
}

// "CONSTRUCTOR": sets the initial values (we must call it ourselves in C)
void student_init(Student *s, const char *studentName, int studentAge) {
    // strncpy copies at most 49 characters so the name can never overflow
    strncpy(s->name, studentName, sizeof(s->name) - 1);
    s->name[sizeof(s->name) - 1] = '\0';
    // We call our own setter here to apply validation!
    student_setAge(s, studentAge);
}

// GETTER (Accessor): safely READ the 'name' data.
const char *student_getName(const Student *s) {
    return s->name;
}

// GETTER for age
int student_getAge(const Student *s) {
    return s->age;
}

int main() {
    // Create a Student object called 's1'
    Student s1;
    student_init(&s1, "Alice", 20);

    // We READ the data using the getters
    printf("Student Name: %s\n", student_getName(&s1));
    printf("Student Age: %d\n", student_getAge(&s1));

    // We MODIFY the data using the setter
    printf("\nAttempting to change age to 25...\n");
    student_setAge(&s1, 25);
    printf("New Age: %d\n", student_getAge(&s1));

    // Trying to set an invalid age
    printf("\nAttempting to change age to -5...\n");
    student_setAge(&s1, -5);   // This will trigger our validation error!
    printf("Age after invalid attempt: %d\n", student_getAge(&s1));

    // In C++ the line below is a COMPILE ERROR because age is private.
    // In C it compiles fine, which is exactly why C needs discipline:
    // s1.age = 30;   // bypasses the validation (do NOT do this)

    return 0;
}