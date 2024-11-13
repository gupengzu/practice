#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"
class Employee:public workers
{
public:
	Employee(int id,string name,int did);
	//显示个人信息
	virtual void showInfo() ;
	//获得岗位职称
	virtual string getDeptName() ;
};
