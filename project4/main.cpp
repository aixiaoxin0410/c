#include <iostream>
using namespace std;
#include<ctime>
#inclu5.2de<fstream>
#include "Identity.h"
#include "GlobalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"

void ManagerMenu(Identity * &manager)
{
    while(true)
    {
        manager->OpenMenu(); 
        Manager* man = (Manager*)manager;

        int select = 0;
        cin >> select;

        if(select == 1)
        {
            cout << "添加账号" << endl;
        }
        else if(select == 2)
        {
            cout << "查看账号" << endl;
        }
        else if(select == 3)
        {
            cout << "查看机房" << endl;
        }
        else if(select == 4)
        {
            cout << "清空预约" << endl;
        }
        else if(select == 0)
        {
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
        }
        else
        {
            cout << "输入有误，请重新输入！" << endl;
            system("pause");
            system("cls");
        }
       
    }
}

void LoginIn(string filename, int type)
{
    Identity * person = NULL;
    ifstream ifs;
    ifs.open(filename,ios::in);
    if(!ifs.is_open())
    {
		cout << "文件不存在" << endl;
		ifs.close();
		return;      
    }

    int id = 0;
    string name;
    string pwd;

    if(type == 1) // 学生
    {
        cout << "请输入你的学号" << endl;
		cin >> id;
    }
    else if (type == 2) // 教师
    {
        cout << "请输入你的职工号" << endl;
		cin >> id;
    }

    cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

    if (type == 1)
	{
		//学生登录验证
        int Sid;
        string Sname;
        string Spwd;
        while (ifs >> Sid && ifs >> Sname && ifs >> Spwd)
        {
			if (Sid == id && Sname == name && Spwd == pwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");

                person = new Student(id, name, pwd);



                return;
            }
        }
        
	}
	else if (type == 2)
	{
		//教师登录验证
        int Tid;
        string Tname;
        string Tpwd;
        while (ifs >> Tid && ifs >> Tname && ifs >> Tpwd)
        {
			if (Tid == id && Tname == name && Tpwd == pwd)
			{
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");

                person = new Teacher(id, name, pwd);


                
                return;
            }
        }
        
	}
	else if(type == 3)
	{
		//管理员登录验证
        string Mname;
        string Mpwd;
        while (ifs >> Mname && ifs >> Mpwd)
        {
			if (Mname == name && Mpwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");

                person = new Manager(name, pwd);

                ManagerMenu(person);    
                
                return;
            }
        }
	}
	
	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;

}

int main() 
{
    srand((unsigned int)time(NULL));
    system("chcp 65001 > nul");

    int select = 0;
    while(true)
    {
        cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";   
        
        cin >> select;
        switch (select)
        {
        case 1: // 学生身份
            LoginIn(STUDENT_FILE,1);
            break;
        case 2: // 教师身份
            LoginIn(TEACHER_FILE,2);
            break;
        case 3: // 管理员身份
            LoginIn(ADMIN_FILE,3);
            break; 
        case 0: // 退出系统
            cout << "欢迎下次使用！" << endl;
            system("pause");
            return 0;
            break;      
        default:
            cout << "输入有误，请重新选择！" << endl;
            system("pause");
            system("cls");        
            break;
        }
    }


    system("pause");
    return 0;
}