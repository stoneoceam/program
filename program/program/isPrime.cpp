#include<iostream>
using namespace std;
inline int isPrime(int n);
int main22() {
	int n;
	cout << "Please enter a number" << endl;
	cin >> n;
	if (isPrime(n))
		cout << n << " is a prime number";
	else
		cout << n << " not a prime number";
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
