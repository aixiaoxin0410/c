#pragma once
#include <iostream>
using namespace std;

#include "AbstrctWorker.h"

class WorkManage
{
public:
    //显示菜单
    void ShowMenu();

    //退出系统
    void ExitSystem();

    //添加职工
    void AddEmp();

    //保存文件
    void SaveFile();

    //读取文件
    void ReadFile();

    //统计职工人数
    int getEmpNum();

    //初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();    

    //删除职工
    void Del_Emp();

    //按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
    int IsExist(int id);
    
    //修改职工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //排序职工
    void Sort_Emp();

    //清空文件
    void Clean_File();

    WorkManage();

    ~WorkManage();

    int m_EmpNum; //记录职工人数
    AbstrctWorker **m_EmpArray; //职工数组指针
	bool m_FileIsEmpty;    //标志文件是否为空
};