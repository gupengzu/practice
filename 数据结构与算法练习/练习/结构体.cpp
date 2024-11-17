#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//typedef struct student
//{
//	char name[100];
//	int age;
//}s;
//void method(s* st);
//int main()
//{
//	s stu = { "zhangsan",12 };
//	method(&stu);
//	printf("%s %d", stu.name, stu.age);
//	return 0;
//}
//void method(s* st)
//{
//	scanf("%s", (*st).name);
//	scanf("%d", &(*st).age);
//	
//}
//typedef struct
//{
//	int a;
//	int b;
//	int c;
//	int d;
//}c;
//int main()
//{
//	c choose = {0,0,0,0};
//	srand(time(NULL));
//	c* p = &choose;
//	for (int i = 0; i < 50; i++)
//	{
//		int ch = rand() % 4 + 1;
//		if (ch == 1)
//		{
//			(*p).a++;
//		}
//		if (ch == 2)
//		{
//			(*p).b++;
//		}
//		if (ch == 3)
//		{
//			(*p).c++;
//		}
//		if (ch == 4)
//		{
//			(*p).d++;
//		}
//	}
//	printf("%d %d %d %d", (*p).a, (*p).b, (*p).c, (*p).d);
//	if ((*p).d > (*p).a and (*p).d > (*p).b and (*p).d > (*p).c)
//	{
//		printf("d");
//	}
//	else if ((*p).c > (*p).b and (*p).c > (*p).a)
//	{
//		printf("c");
//	}
//	else if ((*p).b > (*p).a)
//	{
//		printf("b");
//	}
//	else
//	{
//		printf("a");
//	}
//	return 0;
//}