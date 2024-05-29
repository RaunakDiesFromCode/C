#include <stdio.h>

int rev(int k) {
	int sum = 0;
	while(k!=0) {
		sum = (sum*10) + (k%10);
		k= k/10;
	}
	return sum;
}

int main() {
	int n;
	printf("\nEnter a number: ");
	scanf("%d", &n);
	(n == rev(n))?printf("%d is Palindrome",n):printf("%d is not a Palindrome",n);
	getch();
	return 0;
}