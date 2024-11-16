#include<iostream>
#include<string.h>
using namespace std;
#include"teacher.h"

//默认构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_empIde = empId;
	this->m_name = name;
	this->m_pwd = pwd;
}
//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎老师" << this->m_name << "登录" << endl;
	cout << "1.查看所有预约" << endl;
	cout << "2。审核预约" << endl;
	cout << "0.注销登录" << endl;
	cout<<"请选择您的操作" << endl;
 }
//查看所有预约
void Teacher::showAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约信息" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "~";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号" << of.m_orderData[i]["stuId"];
		cout << "姓名" << of.m_orderData[i]["stuName"];
		cout << "机房号" << of.m_orderData[i]["roomId"];
		string status = "状态";
		//1 审核中 2 已预约 -1 预约失败 0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//审核预约
void Teacher::validOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout<<"待审核的预约记录如下" << endl;

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "~";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "学号" << of.m_orderData[i]["stuId"];
			cout << "姓名" << of.m_orderData[i]["stuName"];
			cout << "机房号" << of.m_orderData[i]["roomId"];
			string status = "状态:审核中";
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;//接受用户选择的预约内容
	int ret = 0;//接受预约结果记录

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1.通过，2.不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
