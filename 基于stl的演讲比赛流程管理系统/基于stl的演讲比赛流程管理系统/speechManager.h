#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include<map>
#include"speaker.h"
#include<algorithm>
class speechManager
{
public:
	//构造函数
	speechManager();
	
	//初始化属性
	void initSpeech();
	
	//创建选手
	void createSpeaker();
	
	//菜单功能
	void showMenu();

	//开始比赛，比赛的整个流程
	void startSpeech();

	//抽签
	void speechDraw();
	//比赛
	void speechContest();
	//显示晋级人员
	void showScores();
	//保存分数
	void saveRecord();
	//退出系统
	void exitSystem();
	//析构函数
	~speechManager();

	//读取记录
	void loadRecord();
	//判断文件是否为空
	bool fileIsEmpty;
	//存放往届记录的容器
	map<int, vector<string>>m_Record;
	//显示往届记录
	void showRecord();
	//清空比赛记录
	void clearRecord();
	//属性
	//第一轮比赛的人员
	vector<int>v1;
	//第一轮晋级的人员
	vector<int>v2;
	//最终的前三名
	vector<int>v3;
	//具体的存储编号和分数的容器
	map<int, Speaker>m_Speaker;
	//存储轮数的变量
	int m_index;
};