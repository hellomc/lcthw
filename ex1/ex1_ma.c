/**
 * Exercise 1. Make It and Break It
 *
 * @author: Michelle Adea
 * @reference: Zed Shaw
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    /* Make my own pizza. */
    char *pizza_name = "Veggie Supreme";
    int no_toppings = 3;
    char *veg_1 = "red bell peppers";
    char *veg_2 = "black olives";
    char *veg_3 = "pineapples";
    int no_cheeses = 2;
    char *cheese_1 = "mozarella";
    char *cheese_2 = "parmesan";

    printf("My favorite pizza is %s.\n\n", pizza_name);
    printf("It has %d toppings.\n", no_toppings);
    printf("The toppings are %s, %s, and %s.\n\n", veg_1, veg_2, veg_3);
    printf("It has %d types of cheese.\n", no_cheeses);
    printf("The types of chesse on the pizza are %s and %s.\n", cheese_1, cheese_2);

    return 0;
}
