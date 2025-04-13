#pragma once
#include <iostream>
using namespace std;

class AbstrctWorker
{
public:

    virtual void ShowInfo() = 0;
    virtual string GetDeptName() = 0;

    int w_id;
    string w_name;
    int w_deptid;
};