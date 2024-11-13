#include<iostream>
#include<string>
using namespace std;
#include"employee.h"

Employee::Employee(int id, string name, int did)
{
	this->m_name = name;
	this->m_deptid = did;
	this->m_id = id;
}
//显示个人信息
void Employee::showInfo()
{
	cout << "员工名称" << this->m_name 
		<< "\t员工编号" << this->m_id 
		<< "\t部门名称" << this->getDeptName() 
		<< "\t职务内容"<<"当牛马" << endl;
}
//获得岗位职称
string Employee::getDeptName()
{
	return "员工";
 }