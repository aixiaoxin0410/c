#include"OrderFile.h"
#include<iostream>
using namespace std;

OrderFile::OrderFile()
{
    ifstream ifs;
    ifs.open(ORDER_FILE,ios::in);

    string Date;
    string Interval;
    string StuId;
    string StuName;
    string RoomId;
    string Status;

    this->o_size = 0;

    while (ifs >> Date && ifs >> Interval && ifs >> StuId && ifs >> StuName && ifs >> RoomId &&  ifs >> Status)
	{
        // cout << Date << endl;
		// cout << Interval << endl;
		// cout << StuId << endl;
		// cout << StuName << endl;
		// cout << RoomId << endl;
		// cout << Status << endl;

        string key;
        string value;
        map<string,string>m;
        
        int pos = Date.find(":");
        if(pos!=-1)
        {   
            key = Date.substr(0,pos);
            value = Date.substr(pos+1,Date.size()-pos-1);
            m.insert(make_pair(key,value));
        }
        // cout << key << endl;
        // cout << value << endl;

        pos = Interval.find(":");
        if(pos!=-1)
        {   
            key = Interval.substr(0,pos);
            value = Interval.substr(pos+1,Interval.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        pos = StuId.find(":");
        if(pos!=-1)
        {   
            key = StuId.substr(0,pos);
            value = StuId.substr(pos+1,StuId.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        pos = StuName.find(":");
        if(pos!=-1)
        {   
            key = StuName.substr(0,pos);
            value = StuName.substr(pos+1,StuName.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        pos = RoomId.find(":");
        if(pos!=-1)
        {   
            key = RoomId.substr(0,pos);
            value = RoomId.substr(pos+1,RoomId.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        pos = Status.find(":");
        if(pos!=-1)
        {   
            key = Status.substr(0,pos);
            value = Status.substr(pos+1,Status.size()-pos-1);
            m.insert(make_pair(key,value));
        }

        this->o_OrderData.insert(make_pair(this->o_size,m));
        this->o_size++;
    }

	// for (map<int, map<string, string>>::iterator it = this->o_OrderData.begin(); it != o_OrderData.end();it++)
	// {
	// 	cout << "key = " << it->first << " value = " << endl;
	// 	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	// 	{
	// 		cout << mit->first << " " << mit->second << " ";
	// 	}
	// 	cout << endl;
	// }

    ifs.close();
}

void OrderFile::UpdateOrder()
{
    if(this->o_size == 0)
    {
        cout << "当前预约记录为0。"  << endl;
        return;
    }

    ofstream ofs(ORDER_FILE,ios::out | ios::trunc);
    for(int i = 0;i<o_size;i++)
    {
        ofs << "Date:" << this->o_OrderData[i]["Date"] << " ";  
        ofs << "Interval:" << this->o_OrderData[i]["Interval"] << " ";  
        ofs << "StuId:" << this->o_OrderData[i]["StuId"] << " ";  
        ofs << "StuName:" << this->o_OrderData[i]["StuName"] << " "; 
        ofs << "RoomId:" << this->o_OrderData[i]["RoomId"] << " ";  
        ofs << "Status:" << this->o_OrderData[i]["Status"] << endl;   

    }
}