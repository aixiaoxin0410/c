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
        cout << Date << endl;
		cout << Interval << endl;
		cout << StuId << endl;
		cout << StuName << endl;
		cout << RoomId << endl;
		cout << Status << endl;

    }
}

void OrderFile::UpdateOrder()
{

}