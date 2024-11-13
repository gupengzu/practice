#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define filename "empFile.txt"

class workmanager
{
public:

	workmanager();
	//显示菜单
	void showMenu();
	//退出系统
	void exitsystem();
	//职工数量
	int m_empnum;
	//职工数组指针
	workers** m_emparray;
	//增加员工信息
	void add_emp();
	//保存文件
	void save();
	//判断文件是否为空 标志
	bool m_fileisempty;
	//统计文件中人数
	int getEmpNum();
	//初始化员工
	void init_emp();
	//显示员工
	void show_emp();
	~workmanager();
};