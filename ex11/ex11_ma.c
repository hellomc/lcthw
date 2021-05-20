#include <stdio.h>

int main(int argc, char *argv[])
{
    int numbers[4] = { 5 };
    char name[4] = { 'm', 'm', 'm', '\0' };

    // print arrays above
    printf("Original Raw Arrays\n");
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n",
            name[0], name[1], name[2], name[3]);
    printf("name: %s\n", name);

    // assign different values to numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // assign different values to name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = '\0';

    // print new init arrays
    printf("New Init Arrays\n");
    printf("numbers: %d %d %d %d\n",
            numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n",
            name[0], name[1], name[2], name[3]);
    printf("full name: %s\n", name);

    // name as a pointer other_name
    char *other_name = "Zed";
    printf("Pointer with other name\n");
    printf("other name: %s\n", other_name);
    printf("other name each: %c %c %c %c\n",
           other_name[0], other_name[1], other_name[2], other_name[3]);

    return 0;
}

