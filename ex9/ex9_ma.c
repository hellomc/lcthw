#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 25;
    while (i >= 0) {
        if (i == 15) {
	    i--;
            continue;
	}
        printf("%d\n", i);
        i--;
    }

    return 0;
}
