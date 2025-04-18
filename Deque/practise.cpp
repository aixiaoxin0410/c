#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<algorithm>
#include<ctime>

class Person
{
public:
    Person(string name, int score)
    {
        this->p_Name = name;
        this->p_Score = score;
    }
    string p_Name;
    int p_Score;
};


void CreatePerson(vector<Person>&v)
{
    string namestr = "ABCDE";
    for(int i =0;i<5;i++)
    {
        Person p("选手",0);
        p.p_Name += namestr[i];
        v.push_back(p);
    }

}

void test01(vector<Person>v)
{
    for(vector<Person>::iterator it = v.begin(); it!=v.end();it++ )
    {
        cout << "姓名：" << (*it).p_Name << " " << "得分：" << (*it).p_Score << endl;
    }
}

void SetScore(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it!=v.end();it++)
    {
        deque<int>d;
        int score = 0 ;
        int sum = 0;
        for(int i=0;i<10;i++)
        {
            score = rand()%41 + 60;
            d.push_back(score);
        }

        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();

        for(deque<int>::iterator dit = d.begin();dit!= d.end();dit++)
        {
            sum += *dit;
        }
        int avg = sum/d.size();
        (*it).p_Score = avg;
    }
}

void ShowPerson(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it!=v.end();it++)
    {
        cout << "姓名：" << (*it).p_Name << " " << "得分：" << (*it).p_Score << endl;
    }
}

int main()
{
    srand((unsigned int) time(NULL));

    vector<Person>v;
    CreatePerson(v);
    // test01(v);
    SetScore(v);
    ShowPerson(v);
    system("cls");
    return 0;
}