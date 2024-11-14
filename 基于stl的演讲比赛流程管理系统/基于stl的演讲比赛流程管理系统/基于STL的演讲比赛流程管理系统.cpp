#include<iostream>
#include<string.h>
using namespace std;
#include"speechManager.h"
#include<ctime>

int main()
{
	srand((unsigned int)time(NULL));
	int choice;
	
	while (1)
	{
		speechManager sm1;
		sm1.showMenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm1.startSpeech();
				break;	
		case 2:
			sm1.showRecord();
				break;		
		case 3:
			sm1.clearRecord();
				break;		
		case 0:
			sm1.exitSystem();
				break;		
		default:
			system("cls");
				break;
		}
	}
	system("pause");
	return 0;
}