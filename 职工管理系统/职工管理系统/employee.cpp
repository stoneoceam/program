#include "employee.h"

Employee::Employee(int Id, string Name, int dId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = dId;
}

void Employee::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}