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

}

// 查看账号
void Manager::ShowPerson()
{
    
}

// 查看机房信息
void Manager::ShowComputer()
{

}

// 清空预约记录
void Manager::CleanFile()
{

}