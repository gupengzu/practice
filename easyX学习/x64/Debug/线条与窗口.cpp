
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#include<stdio.h>
#include<easyx.h>
#include <graphics.h>
using namespace std;
ExMessage msg = { 0 };


void button(int x, int y, int w, int h)
{
	setfillcolor(BROWN);
	fillroundrect(x, y, x + w, y + h, 10, 10);

	outtextxy(x, y, "button");
}


void drawShape()
{
	//点
	putpixel(50, 50, RED);
	//线
	setlinecolor(BLUE);
	setlinestyle(PS_SOLID, 3);
	line(0, 0, 190, 430);

	//矩形
	rectangle(100, 0, 100 + 120, 120);
	fillrectangle(100, 20, 200, 200);
	solidrectangle(100, 200, 300, 400);
	roundrect(111, 112, 151, 252, 10, 10);
	fillroundrect(111, 111, 222, 323, 10, 20);
	circle(20, 28, 54);
	ellipse(400, 200, 800, 250);
}

void drawText()
{

	settextcolor(BROWN);
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	outtextxy(10, 10, "hello");
	int score = 66;
	char str[50] = "";
	sprintf(str, "score:%d", score);
	outtextxy(getwidth() - 100, 0, str);
}


//判断是否在指定的矩形区域
bool inArea(int mx, int my, int x, int y, int w, int h)
{
	if (mx > x && mx<x + w && my>y && my < y + h)
	{
		return true;
	}
	return false;
}


bool button(int x, int y, int w, int h, const char* text)
{
	//绘制按钮;
	if (inArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	else
	{
		setfillcolor(RGB(230, 231, 232));
	}

	fillroundrect(x, y, x + w, y + h, 5, 5);
	//绘制按钮文本
	int hSpace = (w - textwidth(text)) / 2;
	int vSpace = (h - textheight(text)) / 2;
	settextcolor(BLACK);
	outtextxy(x + hSpace, y + vSpace, text);
	//判断按钮是否被点击
	if (inArea && msg.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}


/*int main()
{
	initgraph(640, 480, EX_SHOWCONSOLE|EX_DBLCLKS);
	setbkcolor(RGB(139, 117, 255));
	cleardevice();
	//设置背景模式
	setbkmode(TRANSPARENT);

	//while (1)
	//{
	//	if (peekmessage(&msg, EX_MOUSE))
	//	{
	//			switch (msg.message)
	//			{
	//			case WM_LBUTTONDOWN:
	//				printf("左键按下 pos(%d %d)\n",msg.x,msg.y);
	//				break;
	//			case WM_RBUTTONDOWN:
	//				printf("右键按下 pos(%d %d)\n",msg.x,msg.y);
	//				break;
	//			case WM_MBUTTONDOWN:
	//				printf("中键按下\n");
	//				break;
	//			case WM_MOUSEWHEEL:
	//				printf("滚轮滚动  dir(%d)\n",msg.wheel);
	//				break;
	//			case WM_LBUTTONDBLCLK:
	//				printf("左键双击\n");
	//				break;
	//			case WM_MOUSEMOVE:
	//				break;
	//			}
	//	}
	//}


	//定义小球属性
	int x = 50;
	int y = 50;
	int r = 20;

	int speed = 3;//速度
	int vx = 0;
	int vy = 0;

	int i = 0;
	while (true)
	{
		if (peekmessage(&msg, EX_MOUSE|EX_KEY))
		{

		}
		//双缓冲绘图：所有的绘图代码必须在begin与end之间
		BeginBatchDraw();
		cleardevice();
		if (button(20, 20, 150, 35, "strat game"))
		{
			printf("Start Game! %d \n",i++);
		}
		if (button(300, 20, 150, 35, "End Game"))
		{
			printf("End Game!\n");
		}
		//outtextxy(0, 0, "123456789");
		//按键消息
		if (msg.message == WM_KEYDOWN)
		{
			//printf("keydown\n");
			switch (msg.vkcode)
			{
			case VK_UP:
				vy = -1;
				break;
			case VK_DOWN:
				vy = 1;
				break;
			case VK_LEFT:
				vx = -1;
				break;
			case VK_RIGHT:
				vx = 1;
				break;

			}
		}
		else if (msg.message == WM_KEYUP)
		{
			switch (msg.vkcode)
			{
			case VK_UP:
				vy = 0;
				break;
			case VK_DOWN:
				vy = 0;
				break;
			case VK_LEFT:
				vx = 0;
				break;
			case VK_RIGHT:
				vx = 0;
				break;

			}
		}

		//绘制小球
		setfillcolor(RGB(100, 153, 218));
		solidcircle(x, y, r);
		//更新小球位置
		x += speed * vx;
		y += speed * vy;

		EndBatchDraw();
		Sleep(10);
		//将消息类型设置为0
		msg.message = 0;

	}


	getchar();
}


//int main()
//{
//	//创建窗口
//	initgraph(640,400,EX_SHOWCONSOLE);
//	//设置背景颜色
//	setbkcolor(WHITE);
//	cleardevice();//清屏
//
//	setlinestyle(PS_SOLID, 5);//设置线条样式
//	setfillcolor(YELLOW);//设置填充颜色
//	setlinecolor(BLUE);//设置线条颜色
//	circle(50, 50, 50);
//	fillcircle(50, 150, 50);
//	solidcircle(50, 250, 50);
//
//	//int maye = 0;
//	//printf("请输入数字");
//	//scanf("%d", &maye);
//
//	//printf("%d", maye);
//	settextcolor(RGB(222, 232, 232));
//	settextstyle(20, 0, "楷体");
//	//设置背景模式
//	setbkmode(TRANSPARENT);
//	outtextxy(50, 50,"agadsgs");
//
//	//把文字居中
//	fillrectangle(200,50,500,100);
//	char arr[] = "aeeaeerwef";
//	int width = 300/2-textwidth(arr) / 2;
//	int height = 50 / 2 - textheight(arr) / 2;
//	outtextxy(width+200, height+50, arr);
//
//
//
//	//输出图片
//	IMAGE img11;//定义一个（变量）对象
//	//加载图片
//	loadimage(&img11, "./enemy3_n2.png",120,120);
//	putimage(0, 0, &img11);
//
//	settextcolor(RGB(163, 68, 149));
//	//鼠标消息
//	while (1)
//	{
//		if (MouseHit())
//		{
//			//cleardevice();
//			MOUSEMSG msg = GetMouseMsg();
//			switch (msg.uMsg)
//			{
//			case WM_LBUTTONDOWN:
//				outtextxy(400, 400, "鼠标左键");
//				printf("坐标（%d,%d）", msg.x, msg.y);
//				break;
//			case WM_RBUTTONDOWN:
//				outtextxy(400, 400, "鼠标右键");
//				printf("坐标（%d,%d）", msg.x, msg.y);
//				break;
//			}
//		}
//	}
//
//
//	getchar();
//	closegraph();
//	return 0;
//}*/