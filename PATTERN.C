#include <stdio.h>
int pat1()
{
	int i, j;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

int pat2()
{

	int i, j, k;
	for (i = 3; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 0; k <= (3 - i); k++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

int pat3()
{

	int i, j;
	for (i = 3; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

int pat4()
{

	int i, j, k;
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (k = (3 - i); k >= 0; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	printf("\nProgram 1\n");
	pat1();
	printf("\nProgram 2\n");
	pat2();
	printf("\nProgram 3\n");
	pat3();
	printf("\nProgram 4\n");
	pat4();
	return 0;
}