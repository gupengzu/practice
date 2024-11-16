#include"orderFile.h"

//构造函数
orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FLIE, ios::in);

	string date;	//日期
	string interval;//时间段
	string stuId;	//学生编号
	string stuName; //学生姓名
	string roomId;  //机房编号
	string status;  //预约状态

	this->m_size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << stuId << endl;
		string key;
		string value;
		map<string, string>m;

		//截取时间段
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取学号
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取姓名
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取机房号
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//截取预约状态
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//将小map容器放入到大的map容器中
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
		/*cout << this->m_orderData[1]["stuId"] << endl;*/
	}
	ifs.close();
	/*cout << this->m_orderData[1]["stuId"] << endl;*/
	//测试最大map容器
	//for (map<int, map<string, string>>::iterator it = this->m_orderData.begin(); it != this->m_orderData.end(); it++)
	//{
	//	cout << "key=" << it->first << "value=" << endl;
	//	for (map<string, string>::iterator i = (*it).second.begin(); i != (*it).second.end(); i++)
	//	{
	//		cout <<" key="<<i->first<<" value=" << i->second <<""<< endl;
	//	}
	//}
}
//更新预约记录
void orderFile::updateOrder()
{
	if (this->m_size == 0)
	{
		return;//预约记录0条，直接return
	}
	ofstream ofs(ORDER_FLIE, ios::out|ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] <<endl;
	}

	ofs.close();
}