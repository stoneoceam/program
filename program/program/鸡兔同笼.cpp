/*һ���������м��������ɣ������ö�û���κλ��Ρ�����֪���й���ͷm������nֻ��
���д��������m��n����������ø�����ֻ�����û�к���ĵĽ⣬�����"NO"��*/
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
			cout << "����" << m - i << "ֻ��" << "�ã�" << i << "ֻ��" << endl;
		}
	}
	if (flag == 0)
		cout << "NO";
	system("pause");
	return 0;
}