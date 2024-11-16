#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string.h>
#include"computerroom.h"
#include<vector>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string m_name, string pwd);
	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	// 取消预约
	void cancelOrder();
	//学生学号
	int m_id;
	//机房容器
	vector<computerRoom>vcom;
};