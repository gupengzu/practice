#include<iostream>
using namespace std;
#include"workermanager.h"

int main()
{
	workmanager wm;
	wm.showMenu();

	int choice = 0;

	while (true)
	{
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitsystem();
				break;		
		case 1://增加职工信息
			wm.add_emp();
				break;	
		case 2://显示职工信息
			wm.show_emp();
				break;	
		case 3://删出离职职工
				break;	
		case 4://修改职工信息
				break;	
		case 5://查找职工信息
				break;	
		case 6://按照编号排序
				break;		
		case 7://清空所以文档
				break;
		}
	}

	system("pause");
	return 0;
}