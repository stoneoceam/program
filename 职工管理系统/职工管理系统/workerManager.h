#pragma once
#include<iostream>
#include<algorithm>
#include<fstream>
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

#define FILENAME "empFile.txt"

class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳��������
	void exitSystem();

	//����ְ��
	void Add_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//��������ĵ�
	void Clean_File();

	//�����ļ�
	void save();

	//��������
	~WorkerManager();

	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա������ָ��
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//����ְ������ж�ְ���Ƿ����,�������򷵻�ְ���������е�λ�ã����򷵻�-1
	int  IsExist(int id);

};

bool cmp1(Worker* lhs, Worker* rhs);//����

bool cmp2(Worker* lhs, Worker* rhs);//����
