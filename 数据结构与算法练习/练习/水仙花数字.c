#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	for (int i = 100; i < 1000; i++)
	{
		int b = i % 10;
		int c = (i / 10) % 10;
		int d = i / 100;
		int e = b * b * b + c * c * c + d * d * d;
		if (e == i)
		{
			printf("%d是一个水仙花数字",i);
		}
	}
	
	return 0;
}