#include <stdio.h>

void print_info(char **ptr_1, int *ptr_2, int ptr_len);

void print_info(char **ptr_1, int *ptr_2, int ptr_len)
{
    printf("---\n");

    int i = 0;
    for (i = 0; i < ptr_len; i++) {
        printf("%s has %d years alive.\n", *(ptr_1 + i), *(ptr_2 + i)); 
    }
}

int main(int argc, char *argv[])
{
    // init 2 arrays
    int ages[] = { 23, 42, 10, 75, 2 };

    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // sizeof ages
    int count = 5; // sizeof(ages) / sizeof(int);
    int *my_age = ages;
    int i = 0;

    // 1) Index with Pointer
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
    
    printf("---Print Again---\n");
    print_info(names, my_age, count);
    
    printf("---\n");

    // setup the pointers to beginning of array
    int *cur_age = ages; // casts ages array to int pointer //
    char **cur_name = names;

    // 2) Pointer Arithmetic Index
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }

    printf("---\n");

    // 3) Pointers are Arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // 4) Complex Use of Pointers
    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
