#include "boss.h"

Boss::Boss(int Id, string Name, int dId)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ�𣺹���˾���е�����" << endl;
}

string Boss::getDeptName() {
	return string("�ܲ�");
}