#include<easyx.h>
#include<stdio.h>
#include<iostream>

int main()
{
	initgraph(800, 600);
	setorigin(400, 300);
	setaspectratio(1, -1);

	//circle(0, 0, 300);
	//putpixel(0, 0, RED);
	//putpixel(200, 200, YELLOW);
	//putpixel(200, -200, CYAN);
	//putpixel(-200, -200, GREEN);
	//putpixel(-200, 200, WHITE);

	//int x;
	//int y;
	//for (int i = 0; i < 1000; i++)
	//{
	//	x = rand() % (800 + 1) - 400;
	//	y = rand() % (600 - 1) - 300;
	//	putpixel(x, y, WHITE);
	//}

	//line(-200, 200, 200, -200);
	//line(200, 200, -200, -200);

	//for (int r = 10; r <= 300; r += 10)
	//{
	//	circle(0, 0, r);
	//}

	//rectangle(-200, 100, 200, -100);

	//ellipse(-200, 100, 200, -100);

	system("pause");
	closegraph();
	return 0;
}