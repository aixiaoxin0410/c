#include <iostream>
using namespace std;
#include "SpeechManager.h"

int main() 
{
    system("chcp 65001 > nul");
    SpeechManager sm;

    int choice = 0;
    while(true)
    {
        sm.ShowMenu();
        // sm.test();
        cout << "请输入选择：" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1: //开始比赛
                sm.StartSpeech();
                break;
            case 2: //查看记录
                break;
            case 3: //清空记录
                break;
            case 0: //退出系统
                sm.ExitSystem();
                break;
            default:
                cout << "输入错误，请重新输入！！！" << endl;
                system("pause");
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}