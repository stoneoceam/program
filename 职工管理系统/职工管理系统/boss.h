#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Boss :public Worker
{
public:

	//���캯��
	Boss(int Id, string Name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};

