#pragma once
#include<iostream>
using namespace std;

class Identity
{
public:
    void virtual OpenMenu() = 0;
    
    string i_Name; // 用户名
    string i_Pwd;  // 密码
};