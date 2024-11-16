#include<iostream>
#include<string.h>
#include "student.h"
#include<fstream>
using namespace std;


//默认构造
Student::Student()
{

}
//有参构造
Student::Student(int id, string name, string pwd)
{
	this->m_id = id;
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerRoom com;
	while (ifs >> com.m_comid && ifs >> com.m_maxnum)
	{
		vcom.push_back(com);
	}
	ifs.close();
}
//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << this->m_name << "登录" << endl;
	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "0.注销登录" << endl;
	cout << "请输入您的选择" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一到周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有无，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段" << endl;
	cout<<"1.上午，2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout<<"输入有误，请重新输入" << endl;
	}

	cout<<"请选择机房" << endl;
	/*cout << vcom[1].m_comid << "号机房容量为" << vcom[1].m_maxnum << endl;*/
	for (int i = 0; i < vcom.size(); i++)
	{
		cout << vcom[i].m_comid << "号机房容量为" << vcom[i].m_maxnum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs;
	ofs.open(ORDER_FLIE, ios::app);
	
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuid:" << this->m_id << " ";
	ofs << "stuName:" << this->m_name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}
//查看自身预约
void Student::showMyOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		//cout << atoi(of.m_orderData[i]["stuId"].c_str()) << endl;
		//string 转 int
		//string 用 .c_str() 转 const char*
		//利用  atoi( const char* ) 转 int
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))//找到自身预约
		{
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房" << of.m_orderData[i]["roomId"];
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
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
		{
			cout << i + 1 << "~";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout<<"时间段"<< (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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
// 取消预约
void Student::cancelOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的纪录可以取消，请输入取消的记录" << endl;

	vector<int>v;//存放在最大容器中的下标编号
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		//cout << "124124234" << endl;
		//先判断是自身学号
		if (this->m_id == atoi(of.m_orderData[i]["stuid"].c_str()))
		{
			//cout << "53534534" << endl;
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "~";
				cout << "预约日期：周" << of.m_orderData[i]["date"];
				cout << "时间段" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房号" << of.m_orderData[i]["roomId"];
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;

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
				of.m_orderData[v[select - 1]]["status"] = "0";

				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}
