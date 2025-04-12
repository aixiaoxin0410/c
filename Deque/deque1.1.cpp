#include<iostream>
using namespace std;
#include<deque>
#include<vector>

// void PrintDeque(const deque<int>& d) 
// {
// 	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
// 		cout << *it << " ";

// 	}
// 	cout << endl;
// }

void PrintVector(const vector<int>& v) 
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) 
    {
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
    deque<int>d1;
    for(int i= 0;i<10;i++)
    {
        d1.push_back(i);
    }

    for(int i =0;i<d1.size();i++)
    {
        cout << d1[i] << " ";
    }

    cout << endl;
    // PrintDeque(d1);
}

int main()
{
    test01();
    vector<int> v1 = {123};
    PrintVector(v1);
    system("cls");
    return 0;
}