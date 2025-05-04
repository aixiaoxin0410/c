#include <iostream>
using namespace std;
#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
    this->S_id = id;
    this->i_Name = name;
    this->i_Pwd = pwd;

    ifstream ifs(COMPUTER_FILE,ios::in);
    ComputerRoom com;
    while(ifs >> com.c_Comid && ifs >> com.c_MaxNum)
    {
        vCom.push_back(com);
    }
    ifs.close();
}

// 菜单界面
void Student::OpenMenu()
{
	cout << "欢迎学生代表：" << this->i_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约         |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 申请预约
void Student::ApplyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

    int date = 0 ;
    int interval = 0;
    int room = 0;

    while (true)
    {
        cin >> date;
        if(date>=1 && date<=5)
        {
            break;
        }
        cout << "输入有误，请重新输入！" << endl;
    }

    cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

    while (true)
    {
        cin >> interval;
        if(interval>=1 && interval<=2)
        {
            break;
        }
        cout << "输入有误，请重新输入！" << endl;
    }

    cout << "请选择机房：" << endl;
    for(int i =0 ;i<vCom.size();i++)
    {
        cout << vCom[i].c_Comid << "号机房容量为：" << vCom[i].c_MaxNum << endl;
    }

    while (true)
    {
        cin >> room;
        if(room>=1 && room<=3)
        {
            break;
        }
        cout << "输入有误，请重新输入！" << endl;
    }

    cout << "预约成功！审核中。" << endl;
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::app);
    ofs << "Date:" << date << " ";
	ofs << "Interval:" << interval << " ";
	ofs << "StuId:" << this->S_id << " ";
	ofs << "StuName:" << this->i_Name << " ";
	ofs << "RoomId:" << room << " ";
	ofs << "Status:" << 1 << endl;

    ofs.close();
    hasRecord = true;
    system("pause");
    system("cls");
}

// 查看我的预约
void Student::ShowMyOrder()
{
    OrderFile of;
    if(of.o_size == 0)
    {
        cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
    }

    for(int i =0 ;i<of.o_size;i++)
    {
        if(this->S_id == atoi((of.o_OrderData[i]["StuId"]).c_str()))
        {
            hasRecord = true; // 找到匹配记录
			cout << "预约日期：周" << of.o_OrderData[i]["Date"] << " ";
			cout << "时段：" << (of.o_OrderData[i]["Interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房：" << of.o_OrderData[i]["RoomId"] << " ";
			string status = "状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
            if (of.o_OrderData[i]["Status"] == "1") 
			{
				status += "审核中";
			}
			else if (of.o_OrderData[i]["Status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.o_OrderData[i]["Status"] == "-1")
			{
				status += "审核未通过，预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
        }
    }

    if (!hasRecord) // 如果没有找到匹配的记录
    {
        cout << "无预约记录" << endl;
    }

    system("pause");
	system("cls");
}


// 查看所有预约
void Student::ShowAllOrder()
{
    OrderFile of;
    if(of.o_size == 0)
    {
        cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
    }

    for (int i = 0; i < of.o_size; i++)
	{
		cout << i + 1 << "、 ";

		cout << "预约日期：周" << of.o_OrderData[i]["Date"] << " ";
		cout << "时段：" << (of.o_OrderData[i]["Interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.o_OrderData[i]["StuId"] << " ";
		cout << "姓名：" << of.o_OrderData[i]["StuName"] << " ";
		cout << "机房：" << of.o_OrderData[i]["RoomId"] << " ";
		string status = "状态：";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (of.o_OrderData[i]["Status"] == "1")
		{
			status += "审核中";
		}
		else if (of.o_OrderData[i]["Status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.o_OrderData[i]["Status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

// 取消预约
void Student::CancelOrder()
{
	OrderFile of;
	if (of.o_size == 0 || hasRecord == false)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;

    vector<int>v;
    int index = 1;
    for(int i =0;i<of.o_size;i++)
    {
        if(this->S_id == atoi(of.o_OrderData[i]["StuId"].c_str()))
        {
            if (of.o_OrderData[i]["Status"] == "1" || of.o_OrderData[i]["Status"] == "2")
			{
                v.push_back(i);
                cout <<  index ++  << "、";
                cout << "预约日期：周" << of.o_OrderData[i]["Date"] << " ";
                cout << "时段：" << (of.o_OrderData[i]["Interval"] == "1" ? "上午" : "下午") << " ";
                cout << "机房：" << of.o_OrderData[i]["RoomId"] << " ";
                string status = "状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
                if (of.o_OrderData[i]["Status"] == "1")
                {
                    status += "审核中";
                }
                else if (of.o_OrderData[i]["Status"] == "2")
                {
                    status += "预约成功";
                }
                cout << status << endl;    
            }        
        }  
    }

    cout << "请输入取消的记录,0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//	cout << "记录所在位置： " << v[select - 1] << endl;
				of.o_OrderData[v[select - 1]]["Status"] = "0";
				of.UpdateOrder();
				cout << "已取消预约" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}
    system("pause");
	system("cls");
}
