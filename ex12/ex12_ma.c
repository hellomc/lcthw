#include <stdio.h>

int main(int argc, char *argv[])
{
    // initialize variables
    int areas[] = { 10, 12, 13, 14, 20 }; // array of int
    char name[] = "Zed"; // array of string char
    char full_name[] = { 'Z', 'e', 'd', ' ', 'A', '.', ' ',
                         'S', 'h', 'a', 'w', '\0' }; // array of char

    // check the size of data types and variables
    /* Integer */
    printf("The size of an int: %ld\n", sizeof(int)); // ld is long int

    printf("The size of areas (int[]): %ld\n", sizeof(areas)); // sizeof int arr

    printf("The number of ints in areas: %ld\n",
           sizeof(areas) / sizeof(int)); // no. of int in int arr

    printf("In the integer array areas, the 1st area is %d and the 2nd %d\n", areas[0], areas[1]); // output 1st 2 entries in areas

    printf("\n");

    /* Character String */
    printf("The size of a char: %ld\n", sizeof(char));

    printf("The size of name (char[]): %ld\n", sizeof(name)); // size of char arr

    printf("The number of chars in name: %ld\n",
           sizeof(name) / sizeof(char)); // no. of char in char arr name

    printf("\n");

    /* Character Individual */
    printf("The size of full name (char[]): %ld\n", sizeof(full_name));

    printf("The number of chars: %ld\n",
           sizeof(full_name) / sizeof(char)); // no of char in char arr full name

    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
