#include <stdio.h>

int main() {
    int i, j, k;
    // clrscr();
    for (i = 3; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            printf(" ");
        }
        for (k = 0; k <= (3 - i); k++) {
            printf("*");
        }
        printf("\n");
    }
    // getch();
    return 0;
}
