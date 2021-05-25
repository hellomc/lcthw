#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // loop through each string in argv, skip index 0
    for (i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // init array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Virginia"
    };

    int no_states = 4;
    for (i = 0; i < no_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
