#include<iostream>
#include<string.h>
using namespace std;
#include<fstream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"


//进入学生界面的子菜单
void studentMenu(Identity* &student)
{
	while (true)
	{
		//调用学生的子菜单
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;//接受用户选择

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自己预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			stu->showAllOrder();
		}
		else if(select==4)//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			//注销登录
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*&teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入到管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员的子菜单
		manager->operMenu();

		//将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房信息
		{
			cout << "查看机房信息" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)
	{
		cout << "请输入您的学号：" << endl;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名:"   << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证

		int fId;//从文件中读取id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入到学生身份的子菜单
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证

		int fId;//从文件中读取id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入到教师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证

		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取的密码

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入到管理员身份的子菜单
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证登陆失败" << endl;
	system("pause");
	system("cls");

	return;
}


int main()
{
	int choice = 0;
	while (true)
	{
		cout << "欢迎来到机房预约系统" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t       1.学生代表                \n";
		cout << "\t\t                                \n";
		cout << "\t\t       2.老师                   \n";
		cout << "\t\t                                \n";
		cout << "\t\t       3.管理员                  \n";
		cout << "\t\t                                \n";
		cout << "\t\t       0.退出                   \n";
		cout << "\t\t--------------------------------\n";
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}