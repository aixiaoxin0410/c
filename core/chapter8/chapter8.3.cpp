#include <iostream>
using namespace std;
#include <vector>

void test01()
{
    vector<vector<int>>v;

    vector<int>v1;
    vector<int>v2;

    for(int i=0;i<2;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
    }

    v.push_back(v1);
    v.push_back(v2);

    for(vector<vector<int>>::iterator vit = v.begin();vit!= v.end();vit++)
    {
        for(vector<int>::iterator it = (*vit).begin(); it!= (*vit).end();it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    test01();
    system("cls");
    return 0;
}