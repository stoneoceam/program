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

	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出管理程序
	void exitSystem();

	//增加职工
	void Add_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空所有文档
	void Clean_File();

	//保存文件
	void save();

	//析构函数
	~WorkerManager();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化职工
	void init_Emp();

	//按照职工编号判断职工是否存在,若存在则返回职工在数组中的位置，否则返回-1
	int  IsExist(int id);

};

bool cmp1(Worker* lhs, Worker* rhs);//升序

bool cmp2(Worker* lhs, Worker* rhs);//降序
