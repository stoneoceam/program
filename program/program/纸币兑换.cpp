//把一张100元的人名币兑换成20元,10元,5元的纸币,打印兑换组合
#include<iostream>
using namespace std;
#define N 100
int main6() {
	cout << "组合格式20 10 5" << endl;
	for (int i = 0; i <= N / 20; i++) {
		for (int j = 0; j <= N / 10; j++) {
			for (int k = 0; k <= N / 5; k++) {
				if (i * 20 + j * 10 + k * 5 == N)
					cout << i << " " << j << " " << k << endl;
			}
		}
	}
	system("pause");
	return 0;
}