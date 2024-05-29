#include <stdio.h>

int sum(int k) {
	int i, sum;
	sum = 0;
	while(k!=0) {
		sum = sum + k%10;
		k= k/10;
	}
	return sum;
}

int main() {
	int n;
	printf("\nEnter a number: ");
	scanf("%d", &n);
	printf("Sum of digits of %d is %d",n, sum(n));
	getch();
	return 0;
}