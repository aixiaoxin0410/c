#pragma once
#include <iostream>
using namespace std;

#include "AbstrctWorker.h"

class Boss : public AbstrctWorker
{
public: 
    Boss(int id, string name, int deptid);
    virtual void ShowInfo();
    virtual string GetDeptName();
};
