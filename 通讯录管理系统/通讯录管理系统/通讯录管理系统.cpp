//2022.3.29
//stoneoceam

#include<iostream>
#include<string>
using namespace std;

#define MAX 1000                             //最大容量

struct contact {
	string name;                                     //姓名
	int gender;                                        //性别
	int age;			                                 //年龄
	string phone_number;                     //电话号码
	string address;                                 //居住住址
};
struct arr {
	struct contact person[MAX];
	int size;                                               //当前容量
};


void meun();//菜单
void add_arr_person(struct arr* arr_person);  //添加联系人
void show_arr_person(struct arr* arr_person,int size);  //显示联系人
int delete_arr_person(struct arr* arr_person);  //删除联系人
void find_arr_person(struct arr* arr_person);  //查找联系人
void reise_arr_person(struct arr* arr_person);  //修改联系人
int clear_arr_person(struct arr* arr_person);  //清空联系人


void change_name(struct arr* arr_person, int n);  //修改联系人的名字
void change_gender(struct arr* arr_person, int n);  //修改联系人的性别
void change_age(struct arr* arr_person, int n);  //修改联系人的年龄
void change_phone_number(struct arr* arr_person, int n);  //修改联系人的电话号码
void change_address(struct arr* arr_person, int n);  //修改联系人的住址
int main() {
	struct arr arr_person;
	arr_person.size = 0;
	while (true) {
		system("cls");
		meun();
		int select = 0;
		cin >> select;
		switch (select) {
		case 1:                              //1、添加联系人
			add_arr_person(&arr_person);
			break;
		case 2:                              //2、显示联系人
			show_arr_person(&arr_person, arr_person.size);
			break;
		case 3:                              //3、删除联系人
			arr_person.size = delete_arr_person(&arr_person);
			break;
		case 4:                             //4、查找联系人
			find_arr_person(&arr_person);
			break;
		case 5:                             //5、修改联系人
			reise_arr_person(&arr_person);
			break;
		case 6:                             //6、清空联系人
			arr_person.size = clear_arr_person(&arr_person);
			break;
		case 0:
			cout << "感谢您的使用，再见！" << endl;
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

//菜单
void meun() {
	cout << "**********************" << endl;
	cout << "****1、添加联系人*****"<< endl;
	cout << "****2、显示联系人*****" << endl;
	cout << "****3、删除联系人*****" << endl;
	cout << "****4、查找联系人*****" << endl;
	cout << "****5、修改联系人*****" << endl;
	cout << "****6、清空联系人*****" << endl;
	cout << "****0、退出通讯录*****" << endl;
	cout << "**********************" << endl;
}

//添加联系人
void add_arr_person(struct arr * arr_person) {
	cout << "添加联系人" << endl;
	cout << endl;
	if (arr_person->size == MAX) {
		cout << "系统已满，无法添加联系人!" << endl;
	}
	else {
		cin.get();//吸收回车

		cout << "请输入姓名" << endl;
		string name;
		getline(cin, name);
		arr_person->person[arr_person->size].name = name;

		cout << "请输入性别" << endl;
		cout << "男--1" << endl;
		cout << "女--2" << endl;
		int gender;
		cin >> gender;
		while(gender != 1 && gender != 2) {
			cout << "输入有误，请重新输入" << endl;
			cout << "男--1" << endl;
			cout << "女--2" << endl;
			cin >> gender;
		}
		arr_person->person[arr_person->size].gender = gender;

		cout << "请输入年龄" << endl;
		int age;
		cin >> age;
		arr_person->person[arr_person->size].age = age;

		cin.get();//吸收回车

		cout << "请输入电话号码" << endl;
		string phone_number;
		getline(cin, phone_number);
		arr_person->person[arr_person->size].phone_number = phone_number;

		cout << "请输入住址" << endl;
		string address;
		getline(cin, address);
		arr_person->person[arr_person->size].address = address;
		
		arr_person->size++;     //当前容量+1

		cout << "联系人" << name << "添加成功 " << endl;

		system("pause");
	}
}

//显示联系人
void show_arr_person(struct arr* arr_person,int size) {
	cout << "显示联系人" << endl;
	cout << endl;
	if (size == 0) {
		cout << "通讯录为空" << endl;
		cout << endl;
	}
	else {
		for (int i = 0; i < size; i++) {
			cout << "姓名：" << arr_person->person[i].name << "\t";
			cout << "性别：" << (arr_person->person[i].gender == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << arr_person->person[i].age << "\t";
			cout << "电话号码：" << arr_person->person[i].phone_number << "\t";
			cout << "住址：" << arr_person->person[i].address << "\t" << endl;
			cout << endl;
		}
	}
	system("pause");
}

//删除联系人
int delete_arr_person(struct arr* arr_person) {
	string name;
	cout << "输入需要删除的联系人的姓名" << endl;

	cin.get();//吸收回车

	getline(cin, name);

	int flag = 0;
	int i = 0;
	for (i; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			cout << "已找到联系人:" << name << endl;
			flag = 1;
			break;
		}
	}
	if (flag == 1) {
		if (i == arr_person->size-1) {      //判断删除的是否为最后一个元素
			arr_person->size = arr_person->size-1;
			cout << "联系人：" << name << "删除成功" << endl;
		}
		else {
			for (i; i < arr_person->size - 1; i++) {
				arr_person->person[i] = arr_person->person[i + 1];
			}
			arr_person->size = arr_person->size - 1;
			cout << "联系人：" << name << "删除成功" << endl;
		}
	}
	else {
		cout << "未找到联系人：" << name << endl;
		cout << "联系人：" << name << "删除失败" << endl;
	}

	system("pause");
	return arr_person->size;
}

//查找联系人
void find_arr_person(struct arr* arr_person) {
	cout << "请输入需要查找的联系人的姓名" << endl;
	cin.get();//吸收回车
	string name;
	getline(cin, name);
	int flag = 0;
	for (int i = 0; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			flag = 1;
			cout << "姓名：" << arr_person->person[i].name << "\t";
			cout << "性别：" << (arr_person->person[i].gender == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << arr_person->person[i].age << "\t";
			cout << "电话号码：" << arr_person->person[i].phone_number << "\t";
			cout << "住址：" << arr_person->person[i].address << "\t" << endl;
			cout << endl;
		}
	}
	if (flag == 0)
		cout << "未找到联系人: "<< name << endl;
	
	system("pause");
}

//修改联系人
void reise_arr_person(struct arr* arr_person) {
	cout << "请输入需要修改的联系人的姓名" << endl;
	cin.get();//吸收回车
	string name;
	getline(cin, name);
	int i = 0;
	int flag = 0;
	for (i; i < arr_person->size; i++) {
		if (arr_person->person[i].name == name) {
			cout << "已找到联系人:" << name << endl;
			flag = 1;
			break;
		}
	}
	
	if (flag == 1) {
		cout << "1：修改该项，0：跳过该项" << endl;
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
		cout << "联系人: " << name << "修改完成" << endl;
	}
	else {
		cout << "未找到联系人: " << name << endl;
	}

	system("pause");
}

//清空联系人
int clear_arr_person(struct arr* arr_person) {
	arr_person->size = 0;
	cout << "通讯录清空成功" << endl;
	system("pause");
	return arr_person->size;
}





//修改联系人的名字
void change_name(struct arr* arr_person, int n) {
	int change = 0;
	cout << "是否修改姓名" << endl;
	cin >> change;
	if (change == 1) {
		cout << "输入新姓名" << endl;
		cin.get();//吸收回车
		string name;
		getline(cin, name);
		arr_person->person[n].name = name;
		cout << "姓名修改完成" << endl;
	}
}

//修改联系人的性别
void change_gender(struct arr* arr_person, int n) {
	int change = 0;
	cout << "是否修改性别" << endl;
	cin >> change;
	if (change == 1) {
		cout << "输入新性别" << endl;
		int gender;
		cin >> gender;
		while (gender != 1 && gender != 2) {
			cout << "输入有误，请重新输入" << endl;
			cout << "男--1" << endl;
			cout << "女--2" << endl;
			cin >> gender;
		}
		arr_person->person[n].gender = gender;
		cout << "性别修改完成" << endl;
	}
}
//修改联系人的年龄
void change_age(struct arr* arr_person, int n) {
	int change = 0;
	cout << "是否修改年龄" << endl;
	cin >> change;
	if (change == 1) {
		cout << "输入新年龄" << endl;
		int age;
		cin >> age;
		arr_person->person[n].age = age;
		cout << "年龄修改完成" << endl;
	}
}
//修改联系人的电话号码
void change_phone_number(struct arr* arr_person, int n) {
	int change = 0;
	cout << "是否修改电话号码" << endl;
	cin >> change;
	if (change == 1) {
		cout << "输入新电话号码" << endl;
		cin.get();//吸收回车
		string phone_number;
		getline(cin, phone_number);
		arr_person->person[n].phone_number = phone_number;
		cout << "电话号码修改完成" << endl;
	}
}
//修改联系人的住址
void change_address(struct arr* arr_person, int n) {
	int change = 0;
	cout << "是否修改住址" << endl;
	cin >> change;
	if (change == 1) {
		cout << "输入新住址" << endl;
		cin.get();//吸收回车
		string address;
		getline(cin, address);
		arr_person->person[n].address = address;
		cout << "住址修改完成" << endl;
	}
}

