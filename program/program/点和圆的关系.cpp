//设计一个圆形类(Circle)，和一个点类(Point)，计算点和圆的关系。

#include<iostream>
using namespace std;

class Point
{
public:
	void getPoint(double& x, double& y) {
		cout << "输入点的坐标：x y" << endl;
		cin >> x >> y;
	}
	double x, y;
};

class Circle
{
public:
	void getCircle(double& x, double& y, double& r) {
		cout << "输入圆的圆心坐标与半径：x y r" << endl;
		cin >> x >> y >> r;
	}
	double x, y, r;
};

void position(double x0, double y0, double r, double x, double y) {
	double dd = (x - x0) * (x - x0) + (y - y0) * (y - y0);
	if (dd == r * r)
		cout << "点在圆上" << endl;
	if (dd > r * r)
		cout << "点在圆外" << endl;
	if (dd < r * r)
		cout << "点在圆内" << endl;
}

int main9() {
	Circle c;
	Point p;
	c.getCircle(c.x, c.y, c.r);
	p.getPoint(p.x, p.y);
	position(c.x, c.y, c.r, p.x, p.y);
	return 0;
}