/*��д��������������n����1��+2��+3��+������������+n���ĺ�*/
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
