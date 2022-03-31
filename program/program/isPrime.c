#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
inline int isPrime(int n);
int main21() {
	int n;
	printf("Please enter a number\n");
	scanf("%d", &n);
	if (isPrime(n))
		printf("%d is a prime number",n);
	else
		printf("%d not a prime number", n);
	return 0;
}

int isPrime(int n)
{
	int i = 0;
	for (i = 2; i < n; i++) {
		if (n % i == 0)
			break;
	}
	if (n == i)
		return 1;
	else
		return 0;
}
