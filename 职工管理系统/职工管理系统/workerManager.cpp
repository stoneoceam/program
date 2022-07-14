#include "workerManager.h"

WorkerManager::WorkerManager() {
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//1���ļ����������
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;//�������
		//��ʼ������
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;

		//�ر��ļ�
		ifs.close();
		return;
	}

	//2���ļ����ڣ����ļ��ڲ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;//�������
		//��ʼ������
		this->m_EmpNum = 0;

		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpty = true;

		//�ر��ļ�
		ifs.close();
		return;
	}

	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ��" << num << "��" << endl;//���Դ���
	this->m_EmpNum = num;//���³�Ա����

	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];

	//��ʼ��ְ��
	init_Emp();
}

void WorkerManager::Show_Menu()
{
	cout << "****************************************************" << endl;
	cout << "************** ��ӭʹ��ְ������ϵͳ ****************" << endl;
	cout << "**************** 0.�˳��������*********************" << endl;
	cout << "**************** 1.����ְ����Ϣ*********************" << endl;
	cout << "**************** 2.��ʾְ����Ϣ*********************" << endl;
	cout << "**************** 3.ɾ����ְְ��*********************" << endl;
	cout << "**************** 4.�޸�ְ����Ϣ*********************" << endl;
	cout << "**************** 5.����ְ����Ϣ*********************" << endl;
	cout << "**************** 6.���ձ������*********************" << endl;
	cout << "**************** 7.��������ĵ�*********************" << endl;
	cout << "****************************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "����������ְ��������" << endl;
	
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0) {

		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ��µ����ݷŵ��¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; ++i) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.ְ��" << endl << "2.����" << endl << "3.�ϰ�" << endl;
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

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//���³�Ա����
		this->m_EmpNum = newSize;

		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����Ա����" << endl;

		//�������ݵ��ļ���
		this->save();
	}
	else {
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		//����ְ�����ɾ��
		cout << "��������ɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1) {//ְ������
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������¼�е�����
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "δ�ҵ�ְ����ɾ��ʧ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵ�ְ���ı��" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "ְ���ţ��������µ�ְ����" << endl;
			cin >> newId;

			cout << "������������" << endl;
			cin >> newName;

			cout << "�������¸�λ" << endl;
			cout << "1.ְ��" << endl << "2.����" << endl << "3.�ϰ�" << endl;
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

			cout << "�޸ĳɹ�" << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "δ�ҵ�ְ�����޸�ʧ��" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.������������" << endl;

		int select = 0;
		cin >> select;

		int flag = 0;
		switch (select) {
		case 1: {
			int id;
			cout << "��������ҵ�ְ�����" << endl;
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
			cout << "��������ҵ�ְ������" << endl;
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
			cout << "�������" << endl;
		else
			cout << "δ�ҵ�ƥ���Ա��" << endl;

	}

	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "����������ʽ" << endl;
		cout << "1.���� 2.����" << endl;
		
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
		cout << "�������" << endl;
		this->save();
		system("pause");
		system("cls");
	}
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl; 
	cout << "2.ȡ��" << endl;

	int select = 0;
	cin >> select;

	switch (select) {
	case 1: {
		//��ģʽ ios::frunc �������ɾ���ļ������´���
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
		cout << "����ɹ�" << endl;
	}
	case 2: {
		cout << "��ȡ��" << endl;
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


bool cmp1(Worker* lhs, Worker* rhs)//����
{
	if (lhs->m_Id < rhs->m_Id)
		return true;
	else
		return false;
}

bool cmp2(Worker* lhs, Worker* rhs)//����
{
	if (lhs->m_Id > rhs->m_Id)
		return true;
	else
		return false;
}
