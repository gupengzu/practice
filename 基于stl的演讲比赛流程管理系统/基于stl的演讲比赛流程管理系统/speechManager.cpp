#include "speechManager.h"
#include <deque>
#include<numeric>
#include<fstream>
//构造函数
speechManager::speechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
//初始化
void speechManager::initSpeech()
{
	this->m_index = 1;
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();
}

void speechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "选手";
		name +=nameSeed[i] ;
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_sorce[j] = 0;
		}
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(10001 + i, sp));
	}
}

void speechManager::showMenu()
{
	cout<<"欢迎参加演讲比赛" << endl;
	cout<<"1开始演讲比赛" << endl;
	cout<<"2查看往届记录" << endl;
	cout<<"3清空比赛记录" << endl;
	cout<<"0退出系统" << endl;
}

void speechManager::startSpeech()
{
	//第一轮比赛
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示晋级结果
	this->showScores();
	//第二轮比赛
	this->m_index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示最终结果
	this->showScores();
	//保存分数到文件中
	this->saveRecord();
	//重置比赛，获取记录
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "本届比赛结束" << endl;
	system("pause");
	system("cls");
}

void speechManager::speechDraw()
{
	cout << "第一轮选手正在抽签" << endl;
	cout << "--------------------" << endl;
	cout << "抽签后演讲顺序为下：" << endl;
	if (this->m_index == 1)
	{
		cout << "第一轮比赛" << endl;
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator temp = v1.begin(); temp != v1.end(); temp++)
		{
			cout << *temp<<" ";
		}
		cout << endl;
	}
	else
	{
		cout << "第二轮比赛" << endl;
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator temp = v2.begin(); temp != v2.end(); temp++)
		{
			cout << *temp<<" ";
		}
		cout << endl;
	}
	cout << "----------------" << endl;
	system("pause");
	cout << endl;
}

void speechManager::speechContest()
{
	//准备临时容器，存储小组成绩
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	cout << "第" << this->m_index << "轮比赛开始" << endl;
	vector<int>v_Src;//比赛选手容器
	if (m_index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}
	for (vector<int>::iterator i = v_Src.begin(); i < v_Src.end(); i++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());//排序并去除最高分和最低分
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(),0.0f);
		double avg = sum / (double)d.size();
		cout << "编号" << *i << "平均分" << avg;
		this->m_Speaker[*i].m_sorce[this->m_index-1] = avg;
		groupScore.insert(make_pair(avg, *i));
		if (num % 6 == 0)
		{
			cout << endl;
			cout << "第" << num / 6 << "组的成绩为：" << endl;
			for (multimap<double, int, greater<double>>::iterator i = groupScore.begin(); i != groupScore.end(); i++)
			{
				cout << (*i).first << " ";
			}
			cout << endl;
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator i = groupScore.begin(); i != groupScore.end() && count < 3; i++, count++)
			{
				if (this->m_index == 1)
				{
					v2.push_back((*i).second);
				}
				else
				{
					v3.push_back((*i).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "比完了" << endl;
}

void speechManager::showScores()
{
	cout << "第" << this->m_index << "轮比赛晋级信息" << endl;
	vector<int>v;
	if (this->m_index == 1)
	{
		v = v2;
	}
	else
	{
		v = v3;
	}
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << m_Speaker[*i].m_sorce[this->m_index-1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

void speechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator i = v3.begin(); i != v3.end(); i++)
	{
		ofs << *i << "," << m_Speaker[*i].m_sorce[1]<<",";
	}
	ofs << endl;
	ofs.close();
	cout << "已保存" << endl;
	this->fileIsEmpty = false;
}

void speechManager::exitSystem()
{
	cout << "退出系统" << endl;
	system("pause");
	exit(0);
}

//析构函数
speechManager::~speechManager()
{
}



void speechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;

		vector<string>v;
		int start = 0;
		int pos = -1;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
	for (map<int, vector<string>>::iterator i = this->m_Record.begin(); i != this->m_Record.end(); i++)
	{
		cout << i->first << "冠军编号" << i->second[0] << "分数" << i->second[1] << endl;
	}
}

void speechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号" << this->m_Record[i][0] << "成绩" << this->m_Record[i][1] << " "
			<< "亚军编号" << this->m_Record[i][2] << "成绩" << this->m_Record[i][3] << " "
			<< "季军编号" << this->m_Record[i][4] << "成绩" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

void speechManager::clearRecord()
{
	cout << "是否选择清空比赛记录，是选择1，否选择2" << endl;
	int a;
	cin >> a;
	if (a == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
