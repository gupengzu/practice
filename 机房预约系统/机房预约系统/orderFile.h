#pragma once
#include<iostream>
#include<string.h>
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<map>
using namespace std;

class orderFile
{
public:
	//构造函数
	orderFile();

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_size;

	//记录所有预约信息的容器，key记录条数，value记录键值对信息
	map<int, map<string, string>> m_orderData;
};