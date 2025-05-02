#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

class Manager : public Identity
{
public:
    Manager();

    Manager(string name, string pwd);

    // 菜单界面
    virtual void OpenMenu();

	// 添加账号
	void AddPerson(); 

    // 查看账号
	void ShowPerson();

	// 查看机房信息
	void ShowComputer();

    // 清空预约记录
    void CleanFile();
};