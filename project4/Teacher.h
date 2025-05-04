#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include"OrderFile.h"
#include<vector>

class Teacher : public Identity
{
public:
    Teacher();

    Teacher(int id, string name, string pwd);

    // 菜单界面
    virtual void OpenMenu();

	// 查看所有预约
	void ShowAllOrder(); 

	// 审核预约
	void ValidOrder();

    // 教师编号
    int T_id;
};