#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//Ա����
class Employee :public Worker
{
public:
	
	//���캯��
	Employee(int Id, string Name, int dId);
	
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();

};

