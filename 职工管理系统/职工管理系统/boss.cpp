#include "boss.h"

Boss::Boss(int Id, string Name, int dId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：管理公司所有的事务" << endl;
}

string Boss::getDeptName() {
	return string("总裁");
}