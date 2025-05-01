#include<iostream>
using namespace std;
#include"SpeechManager.h"

SpeechManager::SpeechManager()
{
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;    
}

void SpeechManager::ExitSystem()
{
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::InitSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vwin.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}

void SpeechManager::CreateSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for(int i = 0 ; i<nameseed.size();i++)
	{
		string name = "选手";
		name += nameseed[i];
		Speaker sp;
		sp.s_Name = name;
		for(int j = 0;j<2;j++)
		{
			sp.s_Score[j] = 0;
		}

		this->v1.push_back(i+10001);

		this->m_Speaker.insert(make_pair(i+10001,sp));
	}
	
}

void SpeechManager::test()
{
	this->CreateSpeaker();
	for(map<int,Speaker>::iterator it = m_Speaker.begin();it != m_Speaker.end();it++)
	{
		cout << "编号：" << (*it).first << "	" << "姓名："  << (*it).second.s_Name << " "
		<< "成绩：" << (*it).second.s_Score[0] << endl;
	}

}

void SpeechManager::SpeechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签"<<endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if(this->m_Index == 1)
	{
		random_shuffle(v1.begin(),v1.end());
		for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(),v2.end());
		for(vector<int>::iterator it = v2.begin();it != v2.end();it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
}

void SpeechManager::SpeechContest()
{
	cout << "------------- 第"<< this->m_Index << "轮正式比赛开始：------------- " << endl;

	// 定义一个临时容器
	multimap<double,int,greater<int>> GroupScore;
	int num =0; // 用于统计人数

	vector<int>v_Src;
	if(this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// 评委打分
	for(vector<int>::iterator it = v_Src.begin();it!=v_Src.end();it++)
	{
		num++;
		deque<double>d;
		for(int i =0 ;i<10;i++)
		{
			double score = (rand()%401 + 600) / 10.f;
			d.push_back(score);	
		}
		sort(d.begin(),d.end(),greater<double>());
		d.pop_front();
		d.pop_back();

		double total = accumulate(d.begin(),d.end(),0.0f);
		double avg = total/d.size();

		this->m_Speaker[*it].s_Score[this->m_Index-1] = avg;

		// cout << "编号：" << (*it) << "	" << "姓名：" << this->m_Speaker[*it].s_Name << "	" << "平均分为：" << avg << endl;

		GroupScore.insert(make_pair(avg,*it));

		if(num%6 == 0)
		{
			
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for(multimap<double,int,greater<int>>::iterator it = GroupScore.begin();it!= GroupScore.end();it++)
			{
				cout << "编号：" << (*it).second << "	" << "姓名：" << this->m_Speaker[(*it).second].s_Name << "	" << "平均分为：" << it->first << endl;
			}

			int count = 0;
			for(multimap<double,int,greater<int>>::iterator it = GroupScore.begin();it!= GroupScore.end() && count<3;it++,count++)
			{
				if(this->m_Index == 1)
				{
					v2.push_back(it->second);
				}
				else
				{
					vwin.push_back(it->second);
				}
			}

			GroupScore.clear();
			cout << endl;
		}
	}

	cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}

void SpeechManager::ShowScore()
{
	cout << "---------第" << this->m_Index << "轮晋级选手信息如下：-----------" << endl;
	vector<int>v;
	if(this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vwin;
	}

	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "编号：" << *it << "	" << "姓名：" << this->m_Speaker[(*it)].s_Name << "	" << "分数为：" << this->m_Speaker[(*it)].s_Score[this->m_Index-1] << endl;
	}
	cout << endl;
	v.clear();
	system("pause");
	system("cls");
	this->ShowMenu();

}

void SpeechManager::SaveScore()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out | ios::app);
	for(vector<int>::iterator it = vwin.begin();it!=vwin.end();it++)
	{
		ofs << *it << "," << m_Speaker[*it].s_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	cout << "记录已经保存，本届比赛完毕！" << endl;
	this->FileIsEmpty = false;
	system("pause");
	system("cls");
}

void SpeechManager::LoadRecord()
{
	ifstream ifs("speech.csv",ios::in);
	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "文件为空" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}

	this->FileIsEmpty = false;
	ifs.putback(ch);

	string data;
	int index = 1; 
	while(ifs >> data)
	{
		int pos = -1;
		int start = 0;
		vector<string>v;
		// cout << data << endl;
		while(true)
		{	
			pos = data.find(",",start);
			if(pos == -1)
			{
				v.push_back(data.substr(start));
				break;
			}
			string temp = data.substr(start,pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index,v));
		index++;
	}
	ifs.close();

}

void SpeechManager::StartSpeech()
{
	//第一轮比赛
	//1、抽签
	this->SpeechDraw();

	//2、比赛
	this->SpeechContest();

	//3、显示晋级结果
	this->ShowScore();

	//第二轮比赛
	this->m_Index++;

	//1、抽签
	this->SpeechDraw();
	//2、比赛
	this->SpeechContest();

	//3、显示最终结果
	this->ShowScore();

	//4、保存分数
	this->SaveScore();

	// 重置比赛
	this->InitSpeech();
	this->CreateSpeaker();
	this->LoadRecord();

}

void SpeechManager::ShowRecord()
{
	if(this->FileIsEmpty == true)
	{
		cout << "文件不存在,或记录为空！" << endl;
	}
	else
	{
		int index = this->m_Record.size();
		int i = 0;
		for(map<int,vector<string>>::iterator it = m_Record.begin();it!= m_Record.end() && i<index;it++,i++)
		{
			cout << "第" << i + 1 << "届 " << "冠军编号：" << it->second[0] << " 得分：" << it->second[1] << " " 
				 <<	"亚军编号：" << it->second[2] << " 得分：" << it->second[3] << " " 
				 << "季军编号：" << it->second[4] << " 得分：" << it->second[5] << endl;
		}
	}

	system("pause");
	system("cls");
}

void SpeechManager::ClearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		this->InitSpeech();
		this->CreateSpeaker();
		this->LoadRecord();
		cout << "清空完成！！" << endl;
	}
	else
	{
		cout << "输入错误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}