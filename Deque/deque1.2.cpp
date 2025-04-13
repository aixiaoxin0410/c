#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void PrintDeque(const deque<int>d)
{
    for(int i =0;i<d.size();i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
void test01()
{
    deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

    PrintDeque(d);
    sort(d.begin(),d.end());
    PrintDeque(d);
}

int main()
{
    // test01();
    test01(); 
    system("cls");
    return 0;
}