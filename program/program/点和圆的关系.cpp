//���һ��Բ����(Circle)����һ������(Point)��������Բ�Ĺ�ϵ��

#include<iostream>
using namespace std;

class Point
{
public:
	void getPoint(double& x, double& y) {
		cout << "���������꣺x y" << endl;
		cin >> x >> y;
	}
	double x, y;
};

class Circle
{
public:
	void getCircle(double& x, double& y, double& r) {
		cout << "����Բ��Բ��������뾶��x y r" << endl;
		cin >> x >> y >> r;
	}
	double x, y, r;
};

void position(double x0, double y0, double r, double x, double y) {
	double dd = (x - x0) * (x - x0) + (y - y0) * (y - y0);
	if (dd == r * r)
		cout << "����Բ��" << endl;
	if (dd > r * r)
		cout << "����Բ��" << endl;
	if (dd < r * r)
		cout << "����Բ��" << endl;
}

int main9() {
	Circle c;
	Point p;
	c.getCircle(c.x, c.y, c.r);
	p.getPoint(p.x, p.y);
	position(c.x, c.y, c.r, p.x, p.y);
	return 0;
}