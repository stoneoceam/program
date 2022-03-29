//2022.3.29
//stoneoceam

#include<iostream>
#include<string>
using namespace std;

#define MAX 1000                             //�������

struct contact {
	string name;                                     //����
	int gender;                                        //�Ա�
	int age;			                                 //����
	string phone_number;                     //�绰����
	string address;                                 //��ססַ
};
struct arr {
	struct contact person[MAX];
	int size;                                               //��ǰ����
};


void meun();//�˵�
void add_arr_person(struct arr* arr_person);  //�����ϵ��
void show_arr_person(struct arr* arr_person,int size);  //��ʾ��ϵ��
int delete_arr_person(struct arr* arr_person);  //ɾ����ϵ��
void find_arr_person(struct arr* arr_person);  //������ϵ��
void reise_arr_person(struct arr* arr_person);  //�޸���ϵ��
int clear_arr_person(struct arr* arr_person);  //�����ϵ��


void change_name(struct arr* arr_person, int n);  //�޸���ϵ�˵�����
void change_gender(struct arr* arr_person, int n);  //�޸���ϵ�˵��Ա�
void change_age(struct arr* arr_person, int n);  //�޸���ϵ�˵�����
void change_phone_number(struct arr* arr_person, int n);  //�޸���ϵ�˵ĵ绰����
void change_address(struct arr* arr_person, int n);  //�޸���ϵ�˵�סַ
int main() {
	struct arr arr_person;
	arr_person.size = 0;
	while (true) {
		system("cls");
		meun();
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:                              //1�������ϵ��
			add_arr_person(&arr_person);
			break;
		case 2:                              //2����ʾ��ϵ��
			show_arr_person(&arr_person, arr_person.size);
			break;
		case 3:                              //3��ɾ����ϵ��
			arr_person.size = delete_arr_person(&arr_person);
			break;
		case 4:                             //4��������ϵ��
			find_arr_person(&arr_person);
			break;
		case 5:                             //5���޸���ϵ��
			reise_arr_person(&arr_person);
			break;
		case 6:                             //6�������ϵ��
			arr_person.size = clear_arr_person(&arr_person);
			break;
		case 0:
			cout << "��л����ʹ�ã��ټ���" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

//�˵�
void meun() {
	cout << "**********************" << endl;
	cout << "****1�������ϵ��*****"<< endl;
	cout << "****2����ʾ��ϵ��*****" << endl;
	cout << "****3��ɾ����ϵ��*****" << endl;
	cout << "****4��������ϵ��*****" << endl;
	cout << "****5���޸���ϵ��*****" << endl;
	cout << "****6�������ϵ��*****" << endl;
	cout << "****0���˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}

//�����ϵ��
void add_arr_person(struct arr * arr_person) {
	cout << "�����ϵ��" << endl;
	cout << endl;
	if (arr_person->size == MAX) {
		cout << "ϵͳ�������޷������ϵ��!" << endl;
	}
	else {
		cin.get();//���ջس�

		cout << "����������" << endl;
		string name;
		getline(cin, name);
		arr_person->person[arr_person->size].name = name;

		cout << "�������Ա�" << endl;
		cout << "��--1" << endl;
		cout << "Ů--2" << endl;
		int gender;
		cin >> gender;
		while(gender != 1 && gender != 2) {
			cout << "������������������" << endl;
			cout << "��--1" << endl;
			cout << "Ů--2" << endl;
			cin >> gender;
		}
		arr_person->person[arr_person->size].gender = gender;

		cout << "����������" << endl;
		int age;
		cin >> age;
		arr_person->person[arr_person->size].age = age;

		cin.get();//���ջس�

		cout << "������绰����" << endl;
		string phone_number;
		getline(cin, phone_number);
		arr_person->person[arr_person->size].phone_number = phone_number;

		cout << "������סַ" << endl;
		string address;
		getline(cin, address);
		arr_person->person[arr_person->size].address = address;
		
		arr_person->size++;     //��ǰ����+1

		cout << "��ϵ��" << name << "��ӳɹ� " << endl;

		system("pause");
	}
}

//��ʾ��ϵ��
void show_arr_person(struct arr* arr_person,int size) {
	cout << "��ʾ��ϵ��" << endl;
	cout << endl;
	if (size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		cout << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "������" << arr_person->person[i].name << "\t";
			cout << "�Ա�" << (arr_person->person[i].gender == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << arr_person->person[i].age << "\t";
			cout << "�绰���룺" << arr_person->person[i].phone_number << "\t";
			cout << "סַ��" << arr_person->person[i].address << "\t" << endl;
			cout << endl;
		}
	}
	system("pause");
}

//ɾ����ϵ��
int delete_arr_person(struct arr* arr_person) {
	string name;
	cout << "������Ҫɾ������ϵ�˵�����" << endl;

	cin.get();//���ջس�

	getline(cin, name);

	int flag = 0;
	int i = 0;
	for (i; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			cout << "���ҵ���ϵ��:" << name << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		if (i == arr_person->size-1) {      //�ж�ɾ�����Ƿ�Ϊ���һ��Ԫ��
			arr_person->size = arr_person->size-1;
			cout << "��ϵ�ˣ�" << name << "ɾ���ɹ�" << endl;
		}
		else {
			for (i; i < arr_person->size - 1; i++) {
				arr_person->person[i] = arr_person->person[i + 1];
			}
			arr_person->size = arr_person->size - 1;
			cout << "��ϵ�ˣ�" << name << "ɾ���ɹ�" << endl;
		}
	}
	else {
		cout << "δ�ҵ���ϵ�ˣ�" << name << endl;
		cout << "��ϵ�ˣ�" << name << "ɾ��ʧ��" << endl;
	}

	system("pause");
	return arr_person->size;
}

//������ϵ��
void find_arr_person(struct arr* arr_person) {
	cout << "��������Ҫ���ҵ���ϵ�˵�����" << endl;
	cin.get();//���ջس�
	string name;
	getline(cin, name);
	int flag = 0;
	for (int i = 0; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			flag = 1;
			cout << "������" << arr_person->person[i].name << "\t";
			cout << "�Ա�" << (arr_person->person[i].gender == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << arr_person->person[i].age << "\t";
			cout << "�绰���룺" << arr_person->person[i].phone_number << "\t";
			cout << "סַ��" << arr_person->person[i].address << "\t" << endl;
			cout << endl;
		}
	}
	if (flag == 0)
		cout << "δ�ҵ���ϵ��: "<< name << endl;
	
	system("pause");
}

//�޸���ϵ��
void reise_arr_person(struct arr* arr_person) {
	cout << "��������Ҫ�޸ĵ���ϵ�˵�����" << endl;
	cin.get();//���ջس�
	string name;
	getline(cin, name);
	int i = 0;
	int flag = 0;
	for (i; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			cout << "���ҵ���ϵ��:" << name << endl;
			flag = 1;
			break;
		}
	}
	
	if (flag == 1) {
		cout << "1���޸ĸ��0����������" << endl;
		change_name(arr_person, i);
		cout << endl;
		change_gender(arr_person, i);
		cout << endl;
		change_age(arr_person, i);
		cout << endl;
		change_phone_number(arr_person, i);
		cout << endl;
		change_address(arr_person, i);
		cout << endl;
		cout << "��ϵ��: " << name << "�޸����" << endl;
	}
	else {
		cout << "δ�ҵ���ϵ��: " << name << endl;
	}

	system("pause");
}

//�����ϵ��
int clear_arr_person(struct arr* arr_person) {
	arr_person->size = 0;
	cout << "ͨѶ¼��ճɹ�" << endl;
	system("pause");
	return arr_person->size;
}





//�޸���ϵ�˵�����
void change_name(struct arr* arr_person, int n) {
	int change = 0;
	cout << "�Ƿ��޸�����" << endl;
	cin >> change;
	if (change == 1) {
		cout << "����������" << endl;
		cin.get();//���ջس�
		string name;
		getline(cin, name);
		arr_person->person[n].name = name;
		cout << "�����޸����" << endl;
	}
}

//�޸���ϵ�˵��Ա�
void change_gender(struct arr* arr_person, int n) {
	int change = 0;
	cout << "�Ƿ��޸��Ա�" << endl;
	cin >> change;
	if (change == 1) {
		cout << "�������Ա�" << endl;
		int gender;
		cin >> gender;
		while (gender != 1 && gender != 2) {
			cout << "������������������" << endl;
			cout << "��--1" << endl;
			cout << "Ů--2" << endl;
			cin >> gender;
		}
		arr_person->person[n].gender = gender;
		cout << "�Ա��޸����" << endl;
	}
}
//�޸���ϵ�˵�����
void change_age(struct arr* arr_person, int n) {
	int change = 0;
	cout << "�Ƿ��޸�����" << endl;
	cin >> change;
	if (change == 1) {
		cout << "����������" << endl;
		int age;
		cin >> age;
		arr_person->person[n].age = age;
		cout << "�����޸����" << endl;
	}
}
//�޸���ϵ�˵ĵ绰����
void change_phone_number(struct arr* arr_person, int n) {
	int change = 0;
	cout << "�Ƿ��޸ĵ绰����" << endl;
	cin >> change;
	if (change == 1) {
		cout << "�����µ绰����" << endl;
		cin.get();//���ջس�
		string phone_number;
		getline(cin, phone_number);
		arr_person->person[n].phone_number = phone_number;
		cout << "�绰�����޸����" << endl;
	}
}
//�޸���ϵ�˵�סַ
void change_address(struct arr* arr_person, int n) {
	int change = 0;
	cout << "�Ƿ��޸�סַ" << endl;
	cin >> change;
	if (change == 1) {
		cout << "������סַ" << endl;
		cin.get();//���ջس�
		string address;
		getline(cin, address);
		arr_person->person[n].address = address;
		cout << "סַ�޸����" << endl;
	}
}

