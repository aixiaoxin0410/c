#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"
#include "GlobalFile.h"
#include<fstream>
#include<vector>
#include "Student.h"
#include "Teacher.h"
#include<algorithm>
#include "ComputerRoom.h"

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

    // 初始化容器
	void InitVector();

    // 检测重复
    bool CheckRepeat(int id, int type);

	// 学生容器
	vector<Student> vStu;

	// 教师容器
	vector<Teacher> vTea;

    //机房容器
	vector<ComputerRoom> vCom;
};