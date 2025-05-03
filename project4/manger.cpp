#include <iostream>
using namespace std;
#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
    this->i_Name = name;
    this->i_Pwd = pwd;

    this->InitVector();

    ifstream ifs(COMPUTER_FILE,ios::in);
    ComputerRoom com;
    while(ifs >> com.c_Comid && ifs >> com.c_MaxNum)
    {
        vCom.push_back(com);
    }
    ifs.close();
}

// 菜单界面
void Manager::OpenMenu()
{
    cout << "欢迎管理员："<< this->i_Name << "登录！" << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          1.添加账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          2.查看账号            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          3.查看机房            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          4.清空预约            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t|          0.注销登录            |\n";
    cout << "\t\t|                                |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

// 添加账号
void Manager::AddPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

    string FileName;
    string Tip;
    string ErrorTip;

    ofstream ofs;

    int select = 0;
    cin >> select;

    if(select == 1)
    {
        FileName = STUDENT_FILE;
        Tip = "请输入学号： ";
        ErrorTip = "学号重复，请重新输入：";
    }
    else
    {
        FileName = TEACHER_FILE;
        Tip = "请输入职工编号： "; 
        ErrorTip = "职工号重复，请重新输入：";
    }

    ofs.open(FileName,ios::out | ios::app);

    string name;
    string pwd;
    int id;

    cout << Tip << endl;

    while (true)
    {
        cin >> id;
        bool ret = CheckRepeat(id,select);
		if (ret) //有重复
		{
			cout << ErrorTip << endl;
		}
		else
		{
			break;
		}    
    }
    
	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

    ofs << id << " " << name << " " << pwd << " " << endl;
    cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

    // 初始化容器，防止重复添加bug
    this->InitVector();
}

void PrintStudent(Student &s)
{
	cout << "学号： " << s.S_id << " " << "姓名： " << s.i_Name << " " << "密码：" << s.i_Pwd << endl;
}

void PrintTeacher(Teacher &t)
{
	cout << "学号： " << t.T_id << " " << "姓名： " << t.i_Name << " " << "密码：" << t.i_Pwd << endl;
}

// 查看账号
void Manager::ShowPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
    
    int select = 0;
    cin >> select;
    if(select == 1)
    {
        cout << "所有学生信息如下： " << endl;
        for_each(vStu.begin(), vStu.end(), PrintStudent);
    }
    else
    {
		cout << "所有老师信息如下： " << endl;
        for_each(vTea.begin(), vTea.end(), PrintTeacher);
    }

	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::ShowComputer()
{
    cout << "机房信息如下： " << endl;
    for(vector<ComputerRoom>::iterator it = vCom.begin();it != vCom.end();it++)
    {
        cout << "机房编号： " << it->c_Comid << " " << "机房最大容量： " << it->c_MaxNum << endl;
    }
    system("pause");
	system("cls");
}

// 清空预约记录
void Manager::CleanFile()
{
    ofstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

// 初始化容器
void Manager::InitVector()
{
    vStu.clear();
    vTea.clear();

    ifstream ifs(STUDENT_FILE,ios::in);
    if(!ifs.is_open())
    {
        cout << "文件读取失败" << endl;
		return;       
    }

    Student s;
    while (ifs >> s.S_id && ifs >> s.i_Name && ifs >> s.i_Pwd)
    {
        vStu.push_back(s);
    }

    cout << "当前学生数量为： " << vStu.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    Teacher t;
    while (ifs >> t.T_id && ifs >> t.i_Name && ifs >> t.i_Pwd)
    {
        vTea.push_back(t);
    }

    cout << "当前教师数量为： " << vTea.size() << endl;

    ifs.close();
}

bool Manager::CheckRepeat(int id, int type)
{
    if(type == 1)
    {
        for(vector<Student>::iterator it = vStu.begin();it != vStu.end();it++)
        {
            if(id == it->S_id)
            {
                return true;
            }
        }
    }
    else
    {
        for(vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++)
        {
            if(id == it->T_id)
            {
                return true;
            }
        }
    }

    return false;
}