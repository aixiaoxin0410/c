#include <iostream>
using namespace std;
#include "Teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string pwd)
{
    this->T_id = id;
    this->i_Name = name;
    this->i_Pwd = pwd;
}

// 菜单界面
void Teacher::OpenMenu()
{
	cout << "欢迎教师：" << this->i_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 查看所有预约
void Teacher::ShowAllOrder()
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

// 审核预约
void Teacher::ValidOrder()
{
	OrderFile of;
	if (of.o_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

    vector<int>v;
    int index = 1;
    for(int i =0;i<of.o_size;i++)
    {
        if (of.o_OrderData[i]["Status"] == "1")
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
            cout << status << endl;    
        }        
    }

	cout << "请输入审核的预约记录,0代表返回" << endl;
	int select = 0;
    int ret = 0;
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
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;

                if(ret ==1)
                {
                    of.o_OrderData[v[select-1]]["Status"] = "2";
                }
                else
                {
                    of.o_OrderData[v[select-1]]["Status"] = "-1";
                }
                of.UpdateOrder();
                cout << "审核完毕！" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}
    system("pause");
	system("cls");    
}