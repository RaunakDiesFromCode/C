#include <stdio.h>

int lar(int a, int b, int c) {
	if(a> b) {
		if(c>a) {
			return c;
		}
		return a;
	}
	if((b > a) && (b> c)){
		return b;
	}
}

int main() {
	int a, b, c;
	// clrscr();
	printf("Enter first number: ");
	scanf("%d", &a);
	printf("Enter second number: ");
	scanf("%d", &b);
	printf("Enter third number: ");
	scanf("%d", &c);

	printf("\nLargest among the three: %d", lar(a, b, c));
	// getch();
	return 0;
}

