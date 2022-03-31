/*编写程序，输入正整数n，求1！+2！+3！+······+n！的和*/
#include<iostream>
using namespace std;
long long Factorial(int n);
int main8() {
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += Factorial(i);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
long long Factorial(int n) {
	long long sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}
