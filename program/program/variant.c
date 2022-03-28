#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
inline int isPrime(int n);
int main() {
	int num;
	scanf("%d", &num);
	printf("%d=", num);
	int i = 2;
	int flag = 1;
	while (num != 1) {
		if (isPrime(i)) {
			while (num % i == 0) {
				num = num / i;
				if (flag == 1) {
					printf("%d", i);
					flag = 0;
				}
				else
					printf("*%d", i);
			}
		}
		i++;
	}
	return 0;
}
int isPrime(int n) {
	int flag = 1;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}