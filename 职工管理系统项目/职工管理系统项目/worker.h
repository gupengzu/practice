#pragma once
#include<iostream>
#include<string>
using namespace std;
class workers
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获得岗位职称
	virtual string getDeptName() = 0;
	//职工编号，职工名称，部门编号
	string m_name;
	int m_id;
	int m_deptid;
};