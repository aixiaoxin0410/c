#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include "Speaker.h"
#include<map>

class SpeechManager
{
public:
    SpeechManager();
    ~SpeechManager();

    // 测试函数
    void test();

    // 显示功能菜单
    void ShowMenu();

    // 退出系统
    void ExitSystem();

    // 第一轮12人
    vector<int>v1;

    // 第二轮6人
    vector<int>v2;

    // 胜利三人
    vector<int>vwin;

    // 存放具体选手信息
    map<int, Speaker> m_Speaker;

    // 初始化函数
    void InitSpeech();

    // 记录比赛轮数
    int m_Index;

    // 创建成员函数
    void CreateSpeaker();

    // 开始比赛(大的函数，包括其他小函数)
    void StartSpeech();

    // 抽签函数
    void SpeechDraw();

    // 比赛
    void SpeechContest();

    // 显示晋级结果
    void ShowScore();
};

