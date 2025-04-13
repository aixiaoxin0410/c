#include <iostream>
using namespace std;

#include "Employ.h"

Employ::Employ(int id, string name, int deptid)
{
    this->w_id = id;
    this->w_name = name;
    this->w_deptid = deptid;
}

void Employ::ShowInfo()
{
    cout << "职工编号：" << this->w_id
         << " \t姓名：" << this->w_name
         << " \t岗位：" << this->GetDeptName()
         << " \t职责：完成经理交给的任务" << endl;
}

string Employ::GetDeptName()
{
    return "普通员工";
}