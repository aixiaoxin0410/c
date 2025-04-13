#pragma once
#include <iostream>
using namespace std;

#include "AbstrctWorker.h"

class Employ : public AbstrctWorker
{
public: 
    Employ(int id, string name, int deptid);
    virtual void ShowInfo();
    virtual string GetDeptName();
};
