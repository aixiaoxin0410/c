#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include<vector>
#include "ComputerRoom.h"
#include "GlobalFile.h"
#include<fstream>
#include"OrderFile.h"

class Student : public Identity
{
public:
    Student();

    Student(int id, string name, string pwd);

    // 菜单界面
    virtual void OpenMenu();

    // 申请预约
    void ApplyOrder();

	// 查看我的预约
	void ShowMyOrder(); 

	// 查看所有预约
	void ShowAllOrder(); 

	// 取消预约
	void CancelOrder();

    // 学生学号
    int S_id;

    //机房容器
	vector<ComputerRoom> vCom;
};