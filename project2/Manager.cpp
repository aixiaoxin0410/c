#include <iostream>
using namespace std;

#include "Manager.h"

Manager::Manager(int id, string name, int deptid)
{
    this->w_id = id;
    this->w_name = name;
    this->w_deptid = deptid;
}

void Manager::ShowInfo()
{
    cout << "职工编号：" << this->w_id
         << " \t姓名：" << this->w_name
         << " \t岗位：" << this->GetDeptName()
         << " \t职责：向老板汇报任务" << endl;
}

string Manager::GetDeptName()
{
    return "经理";
}