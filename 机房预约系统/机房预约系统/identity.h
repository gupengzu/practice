#pragma once
#include<iostream>
#include<string.h>
using namespace std;

class Identity
{
public:
	//操作菜单，纯虚函数
	virtual void operMenu() = 0;
	//用户名
	string m_name;
	//密码
	string m_pwd;
};