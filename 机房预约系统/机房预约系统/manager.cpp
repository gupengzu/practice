#include<iostream>
#include<string.h>
using namespace std;
#include"manager.h"
#include"globalFile.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_name = name;
	this->m_pwd = pwd;
	
	//初始化容器，获取到所有文件中 学生和老师的信息
	initVector();
	//初始化机房的信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为"<<vcom.size() << endl;
}
//菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录" << endl;
	cout << "1.添加账号" << endl;
	cout << "2.查看账号" << endl;
	cout << "3.查看机房信息" << endl;
	cout << "4.清空预约" << endl;
	cout << "0.注销登录" << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;//操作文件名
	string tip;     //提示id号
	string errorTip;//重复

	ofstream ofs;   //文件操作对象

	int select = 0;
	cin >> select;//接受用户选项

	if (select == 1)
	{
		//添加的是学生
		fileName = STUDENT_FILE;
		tip = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		//添加的是老师
		fileName = TEACHER_FILE;
		tip = "请输入职工号";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);

	int id;     //学号或职工号
	string name;//姓名
	string pwd; //密码

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret=checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << tip << endl;
	cin >> id;

	cout<<"请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	system("pause");
	system("cls");

	ofs.close();

	//调用初始化容器的接口，重新获取文件中的数据
	this->initVector();
}

//显示学生信息
void printStudent(Student&s)
{
	cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码：" << s.m_pwd << endl;
}

//显示老师信息
void printTeacher(Teacher&t)
{
	cout << "职工号：" << t.m_empIde << "姓名：" << t.m_name << "密码：" << t.m_pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(vstu.begin(), vstu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下" << endl;
		for_each(vtea.begin(), vtea.end(), printTeacher);
	}

	system("pause");
	system("cls");

}
//查看机房信息
void Manager::showComputer()
{
	cout << "查看机房信息" << endl;
	for (vector<computerRoom>::iterator i = vcom.begin(); i != vcom.end(); i++)
	{
		cout << "机房编号：" << i->m_comid <<"机房最大容量："<<i->m_maxnum << endl;
	}

	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FLIE, ios::trunc);
	ofs.close();

	cout<<"清空成功" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector()
{
	//确保容器处于清空状态
	vstu.clear();
	vtea.clear();
	//读取信息  学生  老师
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	//读取学生信息
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vstu.push_back(s);
	}
	cout << "当前学生数量为" << vstu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_empIde && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vtea.push_back(t);
	}
	cout << "当前老师数量为" << vtea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检查学生
		for (vector<Student>::iterator i = vstu.begin(); i != vstu.end(); i++)
		{
			if (i->m_id == id)
			{
				return true;
			}
		}
	}
	if (type == 2)
	{
		//检查老师
		for (vector<Teacher>::iterator i = vtea.begin(); i != vtea.end(); i++)
		{
			if (i->m_empIde == id)
			{
				return true;
			}
		}
	}
	return false;
}
