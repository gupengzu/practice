#include<iostream>
#include<string>
#include"manager.h"
using namespace std;

Manager::Manager(int id, string name, int did)
{
	this->m_name = name;
	this->m_deptid = did;
	this->m_id = id;
}
//显示个人信息
void Manager::showInfo()
{
	cout << "员工名称" << this->m_name
		<< "\t员工编号" << this->m_id
		<< "\t部门名称" << this->getDeptName()
		<< "\t职务内容" << "当高级牛马" << endl;
 }
//获得岗位职称
string Manager::getDeptName()
{
	return "经理";
 }
