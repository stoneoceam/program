//��һ��100Ԫ�������Ҷһ���20Ԫ,10Ԫ,5Ԫ��ֽ��,��ӡ�һ����
#include<iostream>
using namespace std;
#define N 100
int main6() {
	cout << "��ϸ�ʽ20 10 5" << endl;
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