#include <stdio.h>

int main() {
    int num = 10;
    int* ptr = &num;
    int** doublePtr = &ptr;

    printf("Before modification: %d\n", **doublePtr);

    **doublePtr = 20;

    printf("After modification: %d\n", **doublePtr);

    return 0;
}
