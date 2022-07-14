#include<iostream>
#include"workerManager.h"
using namespace std;


void test() {
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(1, "李四", 1);
	worker->showInfo();
	delete worker;


	worker = new Boss(1, "王五", 1);
	worker->showInfo();
	delete worker;

	exit(0);
}


int main() {

	//test();
	
	WorkerManager wm;
	int choice = 0;
	while (true) {

		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出管理程序
			wm.exitSystem();
			break;
		case 1://增加职工信息
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除离职职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}