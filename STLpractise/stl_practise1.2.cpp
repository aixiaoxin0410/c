#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<map>

class Worker
{
public:
    string w_name;
    int w_salary;
};

void CreateWorker(vector<Worker>&vworker)
{

    string namearray = "ABCDEFG";
    for(int i = 0;i<7;i++)
    {
        Worker worker;
        worker.w_name = "员工";
        worker.w_name += namearray[i];
        worker.w_salary = rand() % 5000 + rand() % 10000;
        vworker.push_back(worker);
    }
}

void SetGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
    for(vector<Worker>::iterator it = v.begin();it!=v.end();it++)
    {
        int Deptid = rand()%3;
        m.insert(make_pair(Deptid,*it));
    }
}

void ShowGroup(multimap<int,Worker>&m)
{
    // 策划
    cout << "策划部门：" << endl;
    multimap<int,Worker>::iterator pos = m.find(0);
    int count = m.count(0);
    int index = 0;
    for(;index<count;pos++,index++)
    {
        cout << "姓名：" << pos->second.w_name << " " << "工资：" << pos->second.w_salary << endl;
    }
    cout << endl;

    // 美术
    cout << "美术部门：" << endl;
    pos = m.find(1);
    count = m.count(1);
    index = 0;
    for(;index<count;pos++,index++)
    {
        cout << "姓名：" << pos->second.w_name << " " << "工资：" << pos->second.w_salary << endl;
    }
    cout << endl;

    // 研发
    cout << "研发部门：" << endl;
    pos = m.find(2);
    count = m.count(2);
    index = 0;
    for(;index<count;pos++,index++)
    {
        cout << "姓名：" << pos->second.w_name << " " << "工资：" << pos->second.w_salary << endl;
    }
    cout << endl;

}

int main()
{
    //1.创建员工
    srand((unsigned int)time(NULL));
    vector<Worker>vworker;
    CreateWorker(vworker);

    for(vector<Worker>::iterator it = vworker.begin();it!=vworker.end();it++)
    {
        cout << "姓名：" << it->w_name << " " << "工资：" << it->w_salary << endl;
    }
    cout << endl;

    //2.员工分组
    multimap<int,Worker>gworker;
    SetGroup(vworker,gworker);

    //3.分组显示员工
    ShowGroup(gworker);

    system("cls");
    return 0;
}