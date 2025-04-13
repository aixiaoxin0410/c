#pragma once
#include <iostream>
using namespace std;

#include "AbstrctWorker.h"

class Manager : public AbstrctWorker
{
public: 
    Manager(int id, string name, int deptid);
    virtual void ShowInfo();
    virtual string GetDeptName();
};
