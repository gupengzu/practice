#include"workermanager.h"
#include<iostream>
#include<string.h>
using namespace std;
workmanager::workmanager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	//文件存在且记录数据
	int num = this->getEmpNum();
	//cout << "人数为" << num << endl;
	this->m_empnum = num;
	//开辟空间
	this->m_emparray = new workers * [this->m_empnum];
	this->init_emp();
}
void workmanager::showMenu()
{
	cout << "***********************************" << endl; 
	cout << "*****	欢迎使用职工管理系统!  *****" << endl;
	cout << "********* 0.退出管理程序 *********" << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "3.删除" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********  6.安排编号排序   ********" << endl; 	
	cout << "********  7.清空所有文档   ********" << endl;

}
void workmanager::exitsystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workmanager::add_emp()
{
	cout << "请输入添加人数" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int size = this->m_empnum + addNum;
		workers** newspace = new workers * [size];
		if (this->m_empnum != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
			//增加新的
		for (int i = 0; i < addNum; i++)
		{
			int id;
			int dselect;//部门选择
			string name;
			cout << "请输入第" << i + 1 << "个员工的id" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的name" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个员工的部门" << endl;
			cout << "如果是boss输入3" << endl;
			cout << "如果是manager输入2" << endl;
			cout << "如果是employer输入1" << endl;
			cin >> dselect;
			workers* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker =new Employee(id, name, 1);
				break;				
			case 2:
				worker =new Manager(id, name, 2);
				break;				
			case 3:
				worker =new Boss(id, name, 3);
				break;
			}
			//将建立的职工职责加入到数组中
			newspace[this->m_empnum + i] = worker;
		}
		//释放原有空间
		delete[]this->m_emparray;
		//更新新空间指向
		this->m_emparray = newspace;
		//更新新空间人数
		this->m_empnum = size;
		this->m_fileisempty = false;
		cout << "添加了" << this->m_empnum << "人" << endl;
		//保存
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//保存文件
void workmanager::save()
{
	ofstream ofs(filename, ios::out);//用输出的方式打开文件---写文件
	for (int i = 0; i < this->m_empnum; i++)
	{
		cout << this->m_emparray[i]->m_id << " "
			<< this->m_emparray[i]->m_name << " "
			<< this->m_emparray[i]->m_deptid << endl;
	}
	ofs.close();
}

//统计文件中人数
int workmanager::getEmpNum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs>> name&& ifs>> did)
	{
		num++;
	}
	return num;
}

void workmanager::init_emp()
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	int did;
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		workers* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

void workmanager::show_emp()
{
	if (this->m_fileisempty)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_empnum; i++)
		{
			this->m_emparray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

workmanager::~workmanager()
{
	if (this->m_emparray != NULL)
	{
		delete[]this->m_emparray;
		this->m_emparray = NULL;
	}
}