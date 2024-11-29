#include <stdio.h>
#include <math.h>

int arm(int k) {
	int sum = 0;
	while(k!=0) {
		sum = sum + pow((k%10), 3);
		k= k/10;
	}
	return sum;
}

int main() {
	int n;
	printf("\nEnter a number: ");
	scanf("%d", &n);
	(n == arm(n))?printf("%d is Armstrong",n):printf("%d is not a Armstrong",n);
	// getch();
	return 0;
}
