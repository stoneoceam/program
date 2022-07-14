#include "employee.h"

Employee::Employee(int Id, string Name, int dId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
	return string("员工");
}