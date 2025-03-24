#include <iostream>
using namespace std;

class Building
{
    friend void goodfriend(Building *building); // 全局函数做友元
    friend class House; // 类做友元
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

    void visithouse(House *house)
    {
        cout << "朋友正在访问: " << house->housepos << endl;
        cout << "朋友正在访问: " << house->building->m_sittingRoom << endl;
        cout << "朋友正在访问: " << house->building->m_bedRoom << endl;
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
    house1.visithouse(&house1);
    system("cls");
    return 0;
}