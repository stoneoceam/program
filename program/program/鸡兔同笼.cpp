/*一个笼子里有鸡和兔若干，鸡和兔都没有任何畸形。现已知笼中共有头m个，脚n只。
请编写程序，输入m和n，输出鸡和兔各多少只。如果没有合理的的解，则输出"NO"。*/
#include<iostream>
#define r_f 4
#define c_f 2
using namespace std;
int main7() {
	int m, n;
	cin >> m >> n;
	int flag = 0;
	for (int i = 0; i <= m; i++) {
		if (r_f * i + c_f * (m - i) == n) {
			flag = 1;
			cout << "鸡：" << m - i << "只，" << "兔：" << i << "只。" << endl;
		}
	}
	if (flag == 0)
		cout << "NO";
	system("pause");
	return 0;
}