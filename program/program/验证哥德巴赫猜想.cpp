//验证哥德巴赫猜想：任何一个不小于6的偶数均可表示为两个奇素数之和
#include<iostream>
using namespace std;
inline int isPrime(int i);
int main5() {
	int n;
	cin >> n;
	if (n % 2 == 0 && n >= 6) {
		for (int i = 3; i < n; i++) {
			if (isPrime(i) && isPrime(n - i))
				cout << n << "=" << i << "+" << n - i << endl;
		}
	}
	system("pause");
	return 0;
}
int isPrime(int i) {
	int flag = 1;
	if (i % 2 != 0) {
		for (int k = 2; k < i; k++) {
			if (i % k == 0) {
				flag = 0;
				break;
			}
		}
	}
	else
		flag = 0;
	if (flag)
		return 1;
	else
		return 0;
}