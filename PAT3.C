#include <stdio.h>

int main() {

int i, j;
clrscr();
for(i = 3; i >=0; i--) {
for(j = 0; j <= i; j++) {
printf("*");
}
printf("\n");
}
getch();
return 0;
}