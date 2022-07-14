#include "workerManager.h"

WorkerManager::WorkerManager() {
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//1、文件不存在情况
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;//测试输出
		//初始化人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件为空
		this->m_FileIsEmpty = true;

		//关闭文件
		ifs.close();
		return;
	}

	//2、文件存在，但文件内部为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;//测试输出
		//初始化人数
		this->m_EmpNum = 0;

		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件为空
		this->m_FileIsEmpty = true;

		//关闭文件
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	//cout << "职工个数为：" << num << "人" << endl;//测试代码
	this->m_EmpNum = num;//更新成员属性

	//根据职工数创建数组
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//初始化职工
	init_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "************** 欢迎使用职工管理系统 ****************" << endl;
	cout << "**************** 0.退出管理程序*********************" << endl;
	cout << "**************** 1.增加职工信息*********************" << endl;
	cout << "**************** 2.显示职工信息*********************" << endl;
	cout << "**************** 3.删除离职职工*********************" << endl;
	cout << "**************** 4.修改职工信息*********************" << endl;
	cout << "**************** 5.查找职工信息*********************" << endl;
	cout << "**************** 6.按照编号排序*********************" << endl;
	cout << "**************** 7.清空所有文档*********************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工的数量" << endl;
	
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下的内容放到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位" << endl;
			cout << "1.职工" << endl << "2.经理" << endl << "3.老板" << endl;
			cin >> dSelect;
			
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新成员个数
		this->m_EmpNum = newSize;

		//更新职工不为空
		this->m_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "个新员工！" << endl;

		//保存数据到文件中
		this->save();
	}
	else {
		cout << "输入有误" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		//按照职工编号删除
		cout << "请输入想删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1) {//职工存在
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组记录中的人数
			this->save();

			cout << "删除成功" << endl;
		}
		else {
			cout << "未找到职工，删除失败" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入需要修改的职工的编号" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "职工号，请输入新的职工号" << endl;
			cin >> newId;

			cout << "请输入新姓名" << endl;
			cin >> newName;

			cout << "请输入新岗位" << endl;
			cout << "1.职工" << endl << "2.经理" << endl << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else {
			cout << "未找到职工，修改失败" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找的方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按照姓名查找" << endl;

		int select = 0;
		cin >> select;

		int flag = 0;
		switch (select) {
		case 1: {
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Id == id) {
					this->m_EmpArray[i]->showInfo();
					flag = 1;
				}
			}
			break;
		}
		case 2: {
			string name;
			cout << "请输入查找的职工姓名" << endl;
			cin >> name;
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					this->m_EmpArray[i]->showInfo();
					flag = 1;
				}
			}
			break; 
		}
		default:
			break;
		}
		if (flag)
			cout << "查找完成" << endl;
		else
			cout << "未找到匹配的员工" << endl;

	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入排序方式" << endl;
		cout << "1.升序 2.降序" << endl;
		
		int select = 0;
		cin >> select;

		switch (select) {
		case 1: {
			sort(&m_EmpArray[0], &m_EmpArray[m_EmpNum],cmp1);
			break;
		}
		case 2: {
			//sort(this->m_EmpArray[0], this->m_EmpArray[this->m_EmpNum], cmp2);
			break;
		}
		default:
			break;
		}
		cout << "排序完成" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确定" << endl; 
	cout << "2.取消" << endl;

	int select = 0;
	cin >> select;

	switch (select) {
	case 1: {
		//打开模式 ios::frunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清除成功" << endl;
	}
	case 2: {
		cout << "已取消" << endl;
		break;
	}
	default:
		break;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; ++i) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << " " << endl;
	}

	ofs.close();
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	
	int num = 0;
	
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}

	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		switch (dId) {
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		this->m_EmpArray[index++] = worker;
	}

	ifs.close();
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id){
			index = i;
			break;
		}
	}
	return 0;
}


bool cmp1(Worker* lhs, Worker* rhs)//升序
{
	if (lhs->m_Id < rhs->m_Id)
		return true;
	else
		return false;
}

bool cmp2(Worker* lhs, Worker* rhs)//降序
{
	if (lhs->m_Id > rhs->m_Id)
		return true;
	else
		return false;
}
