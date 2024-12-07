#include"Management.h"
#include"Window.h"
#include"Table.h"
#include<iostream>

//int main()
//{
//	auto res=Table::split("12410101\t张三\t计算机01班\t10\t40\t50");
//	
//	for (auto& val : res)
//	{
//		cout << val << " ";
//
//	}
//	
//	return 0;
//}



int main()
{
	Window w(960, 640, EX_SHOWCONSOLE);
	w.setWindowTitle("学生成绩管理系统");

	Management m;
	m.run();
	return w.exec();
}