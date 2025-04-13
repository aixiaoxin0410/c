#include <iostream>
using namespace std;

//class House; // 前置声明，为函数做友元准备

class Building
{
    friend void goodfriend(Building *building); // 全局函数做友元
    friend class House; // 类做友元
    //friend void House::visitbuilding(Building *building); // 函数做友元


public:
    string m_sittingRoom;

    Building()
    {
        m_sittingRoom = "客厅";
        m_bedRoom = "卧室";
    }
    
private:
    string m_bedRoom;
};

class House
{

public:
    string housepos;
    Building *building;

    House()
    {
        housepos = "北边";building = new Building(); // 初始化 building 指针
    }

    // 添加析构函数，释放内存
    ~House()
    {
        delete building;
    }


    // void visithouse(House *house)
    // {
    //     cout << "朋友正在访问的位置是: " << house->housepos << endl;
    //     cout << "朋友正在访问: " << house->building->m_sittingRoom << endl;
    //     cout << "朋友正在访问: " << house->building->m_bedRoom << endl;
    // }

    void visitbuilding(Building *building)
    {
        cout << "朋友正在访问: " << building->m_sittingRoom << endl;
        cout << "朋友正在访问: " << building->m_bedRoom << endl;
    }

};

void goodfriend(Building *build)
{
    cout << "朋友正在访问: " << build->m_sittingRoom << endl;
    cout << "朋友正在访问: " << build->m_bedRoom << endl;
}

int main() 
{
    Building building1;

    House house1;
    // house1.visithouse(&house1);
    house1.visitbuilding(&building1);

    system("cls");
    return 0;
}