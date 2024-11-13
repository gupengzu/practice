#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Manager:public workers
{
public:
	Manager(int id, string name, int did);
	//显示个人信息
	virtual void showInfo() ;
	//获得岗位职称
	virtual string getDeptName() ;

};