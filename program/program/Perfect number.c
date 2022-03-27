#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main4() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int k[1001];
		int h = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
				k[h] = j;
				h++;
			}
		}
		if (sum == i) {
			printf("%d=", i);
			int p = 0;
			for (p = 0; p < h - 1; p++) {
				printf("%d+", k[p]);
			}
			printf("%d,", k[p]);
			printf("其中");
			for (p = 0; p < h - 1; p++) {
				printf("%d、", k[p]);
			}
			printf("%d", k[p]);
			printf("为因子，%d为因子和\n", i);
		}
	}
	return 0;
}