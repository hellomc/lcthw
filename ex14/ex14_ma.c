#include <stdio.h>
#include <ctype.h>

// function declarations
int can_print_it(char ch);
void print_letters(char arg[]);

// calls print_letters for each argument
void print_arguments( int argc, char *argv[])
{
    int i = 1;

    for (i = 1; i < argc; i++) {
        print_letters(argv[i]);
    }
}

// prints char with corresponding int value
void print_letters(char arg[])
{
    int i = 0;

    for (i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        if (can_print_it(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }
}

// checks if char is in alphabet or blank
int can_print_it(char ch)
{
    return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
