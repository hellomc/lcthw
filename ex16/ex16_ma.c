#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Declare the struct Person
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// Create the struct Person with function Person_create
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // alloc RAM for struct Person
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL); // checks it does not equal NULL

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

// Destroy the struct Person
void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    
    // free pointers
    free(who->name);
    free(who);
}

// Print out properties of struct Person
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // create two people structures
    struct Person *abigail = Person_create("Abigail Adams", 25, 60, 145);

    struct Person *beth = Person_create("Beth Banks", 32, 58, 125);

    // print out the memory address and name
    printf("%s is at memory location %p:\n", abigail->name, abigail);
    Person_print(abigail);

    printf("%s is at memory location %p:\n", beth->name, beth);
    Person_print(beth);

    // age both people by 20 years and print again
    abigail->age += 20;
    abigail->height -= 2;
    abigail->weight += 15;
    Person_print(abigail);

    beth->age += 20;
    beth->height -= 2;
    beth->weight += 15;
    Person_print(beth);

    // destroy both structs for memory cleanup
    Person_destroy(abigail);
    Person_destroy(beth);

    return 0;
}
