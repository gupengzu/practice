#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Boss :public workers
{
public:
	Boss(int id, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获得岗位职称
	virtual string getDeptName();
};