#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define MAX 1000

struct Person 
{
    string m_Name;
    string m_gender;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks 
{
    Person personArray[MAX];
    int m_Size;
};

void ShowMenu() 
{
    cout << "0. 退出通讯录" << endl;
    cout << "1. 添加联系人" << endl;
    cout << "2. 显示联系人" << endl;
    cout << "3. 删除联系人" << endl;
    cout << "4. 查找联系人" << endl;
    cout << "5. 修改联系人" << endl;
    cout << "6. 清空联系人" << endl;
}

void Exit() {
    cout << "欢迎下次使用!" << endl;
    exit(0);
}

void errpr() {
    cout << "输入错误，请重新输入！" << endl;
	system("pause"); // 暂停以便用户看到成功信息
    system("cls");   // 清屏	
}

// 添加联系人
void addperson(AddressBooks &abs) 
{
    if (abs.m_Size == MAX) 
	{
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }

    string name, gender, phone, addr;
    int age;
    cout << "请输入姓名：";
    cin >> name;
    abs.personArray[abs.m_Size].m_Name = name;

    cout << "请输入性别：";
    cin >> gender;
    abs.personArray[abs.m_Size].m_gender = gender;

    cout << "请输入年龄：";
    cin >> age;
    abs.personArray[abs.m_Size].m_Age = age;

    cout << "请输入电话：";
    cin >> phone;
    abs.personArray[abs.m_Size].m_Phone = phone;

    cout << "请输入住址：";
    cin >> addr;
    abs.personArray[abs.m_Size].m_Addr = addr;

    abs.m_Size++;
    cout << "人员添加成功！" << endl;
    system("pause"); // 暂停以便用户看到成功信息
    system("cls");   // 清屏
}

// 显示联系人
void showperson(AddressBooks &abs) {
    if (abs.m_Size == 0) 
	{
        cout << "当前记录为空！" << endl;
        system("pause"); // 暂停，让用户看到信息
        system("cls");   // 清屏
        return;
    }
	cout << "共有联系人：" << abs.m_Size << "人" << endl;
    for (int i = 0; i < abs.m_Size; i++) 
	{
        cout << "姓名：" << abs.personArray[i].m_Name << "\t";
        cout << "性别：" << abs.personArray[i].m_gender << "\t";
        cout << "年龄：" << abs.personArray[i].m_Age << "\t";
        cout << "电话：" << abs.personArray[i].m_Phone << "\t";
        cout << "住址：" << abs.personArray[i].m_Addr << endl;
    }
    system("pause");
    system("cls");
}

// 删除联系人
void deleteperson(AddressBooks &abs) 
{
    if (abs.m_Size == 0) {
        cout << "当前记录为空！" << endl;
        system("pause");
        system("cls");
        return;
    }
    string name;
    cout << "请输入要删除的联系人姓名：";
    cin >> name;
    int i;
	bool found = false; // 标记是否找到联系人
    for (i = 0; i < abs.m_Size; i++) 
	{
        if (abs.personArray[i].m_Name == name) 
		{
            for (int j = i; j < abs.m_Size - 1; j++) 
			{
                abs.personArray[j] = abs.personArray[j + 1];
            }
            abs.m_Size--;
			found = true;
            cout << "删除成功！" << endl;
            break;
        }
    }
	if (!found)
	{ // 如果没找到联系人
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}

//查找联系人
void foundperson(AddressBooks &abs)
{
	cout << "请输入要查找的联系人姓名：";
	string name;
	cin >> name;
	if(abs.m_Size == 0)
	{
		cout << "此记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
   
	int flag = 0; // 标记是否找到联系人

	int i;
	for(i=0; i<abs.m_Size; i++)
	{
		if(abs.personArray[i].m_Name == name)
		{	
			cout << "姓名：" << abs.personArray[i].m_Name << "\t";
			cout << "性别：" << abs.personArray[i].m_gender << "\t";
			cout << "年龄：" << abs.personArray[i].m_Age << "\t";
			cout << "电话：" << abs.personArray[i].m_Phone << "\t";
			cout << "住址：" << abs.personArray[i].m_Addr << endl;
			flag = 1;
		}

	}
	if(flag == 0 )
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
	
}

// 修改联系人
void modifyperson(AddressBooks &abs)
{
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;

	int flag = 0; // 标记是否找到联系人

	if(abs.m_Size == 0)
	{
		cout << "此记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		int i;
		for(i=0; i<=abs.m_Size; i++)
		{
			if(abs.personArray[i].m_Name == name)
			{
				string name;
				cout << "请输入新的姓名：" << endl;
				cin >> name;
				abs.personArray[i].m_Name = name;
	
				string gender;
				cout << "请输入新的性别：" << endl;
				cin >> gender;
				abs.personArray[i].m_gender = gender;
	
				int age;
				cout << "请输入新的年龄：" << endl;
				cin >> age;
				abs.personArray[i].m_Age = age;
	
				string phone;
				cout << "请输入新的电话：" << endl;
				cin >> phone;
				abs.personArray[i].m_Phone = phone;
	
				string addr;
				cout << "请输入新的住址：" << endl;
				cin >> addr;
				abs.personArray[i].m_Addr = addr;

				cout << "修改成功！" << endl;
				flag = 1;
			}

		}	
		if(flag == 0)
		{
			cout << "查无此人！" << endl;
		}
		system("pause");
		system("cls");

	}

}

//清空联系人
void clearperson(AddressBooks &abs)
{
	abs.m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}


int main() 
{
    AddressBooks abs;
    abs.m_Size = 0;
    int select = 0;

    while (true) {
        ShowMenu();
        cout << endl << "请输入您的选择：";
        if (!(cin >> select)) { // 处理非整数输入
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            errpr();
            system("pause");
            system("cls");
            continue;
        }

        switch (select) 
		{
            case 0:
                Exit();
                break;
            case 1:
                addperson(abs);
                break;
            case 2:
                showperson(abs);
                break;
            case 3:
                deleteperson(abs);
                break;
            case 4: 
				foundperson(abs);
                break;
            case 5: 
				modifyperson(abs);
                break;
            case 6: 
				clearperson(abs);
                break;
            default:
                errpr();
                break;
        }
    }
    return 0;
}