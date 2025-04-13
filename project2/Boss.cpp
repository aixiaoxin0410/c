#include <iostream>
using namespace std;

#include "Boss.h"

Boss::Boss(int id, string name, int deptid)
{
    this->w_id = id;
    this->w_name = name;
    this->w_deptid = deptid;
}

void Boss::ShowInfo()
{
    cout << "职工编号：" << this->w_id
         << " \t姓名：" << this->w_name
         << " \t岗位：" << this->GetDeptName()
         << " \t职责：给经理布置任务" << endl;
}

string Boss::GetDeptName()
{
    return "老板";
}