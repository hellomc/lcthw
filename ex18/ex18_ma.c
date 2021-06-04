/**
 * Create a program that uses a pointer to a function.
 *
 * LCTHW Exercise 18
 * Topics: Pointer, Function, Malloc
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Reuse die function from ex17
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// typedef creates fake type for function pointer
typedef int(*compare_cb) (int a, int b);

/**
 * Fundamental bubble sort function that uses compare_cb
 * for sorting.
 *
 * Args:
 * numbers  pointer to an integer
 * count    integer
 * cmp      pointer to compare_cb function
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("ERROR: Memory.");

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        for (j = 0; j < count - 1; j++) {
            if (cmp(target[j], target[j+1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Tests items are being sorted correctly. Output results.
 *
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = bubble_sort(numbers, count, cmp);

    if (!sorted)
        die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted); // remember to free pointer
}

// ?
void destroy(compare_cb cmp)
{
    int i = 0;

    unsigned char *data = (unsigned char *)cmp;

    for (i = 0; i < 1; i++) {
        data[i] = i;
    }
    printf("\n");
}

// Casts function pointer to unsigned char pointer. Outputs data in hexadecimal format.
void dump(compare_cb cmp)
{
    int i = 0;
    
    unsigned char *data = (unsigned char *)cmp;
    
    for (i = 0; i < 25; i++) {
        printf("%02x:", data[i]);  // format specifier x->hexadecimal
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers)
        die("ERROR: Memory.");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    // run tests
    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    printf("SORTED:");
    dump(sorted_order);

    destroy(sorted_order);

    printf("SORTED:");
    dump(sorted_order);

    return 0;
}
