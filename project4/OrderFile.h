#pragma once
#include<iostream>
using namespace std;
#include"GlobalFile.h"
#include<fstream>
#include<map>

class OrderFile
{
public:
    OrderFile();

    void UpdateOrder();

    int o_size;
    map<int,map<string,string>> o_OrderData;
};