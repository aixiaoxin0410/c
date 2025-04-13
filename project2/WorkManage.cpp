#include <iostream>
using namespace std;

#include <fstream>

#include "AbstrctWorker.h"
#include "Employ.h"
#include "Manager.h"
#include "Boss.h"
#include "WorkManage.h"

#define EMP_FILE "empfile.txt"

WorkManage::WorkManage()
{

    ifstream ifs;
    ifs.open(EMP_FILE, ios::in);

    //1.文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl; //测试输出
        this->m_EmpNum = 0;  //初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }

    //2.文件存在，并且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

    //3.文件存在，并且有记录
    int getNum = this->getEmpNum(); //获取职工人数
    // cout << "职工人数为：" << getNum << endl; //测试输出
    this->m_EmpNum = getNum; //初始化人数

    //根据职工数创建数组
	this->m_EmpArray = new AbstrctWorker *[this->m_EmpNum];
	//初始化职工
	init_Emp();

	// //测试代码
	// for (int i = 0; i < m_EmpNum; i++)
	// {
	// 	cout << "职工号： " << this->m_EmpArray[i]->w_id
	// 		<< " \t职工姓名： " << this->m_EmpArray[i]->w_name
	// 		<< " \t部门编号： " << this->m_EmpArray[i]->w_deptid << endl;
	// }

}

void WorkManage::init_Emp()
{
	ifstream ifs;
	ifs.open(EMP_FILE, ios::in);

	int id;
	string name;
	int dId;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		AbstrctWorker *abstrctworker = NULL;
		//根据不同的部门Id创建不同对象
		if (dId == 1)  // 1普通员工
		{
			abstrctworker = new Employ(id, name, dId);
		}
		else if (dId == 2) //2经理
		{
			abstrctworker = new Manager(id, name, dId);
		}
		else //总裁
		{
			abstrctworker = new Boss(id, name, dId);
		}
		//存放在数组中
		this->m_EmpArray[index] = abstrctworker;
		index++;
	}

    ifs.close(); //关闭文件
}

WorkManage::~WorkManage()
{
    if (this->m_EmpArray != NULL)
    {
        // 释放每个职工对象的内存
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
        }
        // 释放数组本身
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

//显示菜单
void WorkManage::ShowMenu()
{
    cout << "**************************" << endl;
    cout << "*****  欢迎使用职工管理系统  *****" << endl;
    cout << "********  0.退出管理程序  ********" << endl;
    cout << "********  1.增加职工信息  ********" << endl;
    cout << "********  2.显示职工信息  ********" << endl;
    cout << "********  3.删除离职职工  ********" << endl;
    cout << "********  4.修改职工信息  ********" << endl;
    cout << "********  5.查找职工信息  ********" << endl;
    cout << "********  6.按照编号排序  ********" << endl;
    cout << "********  7.清空所有文档  ********" << endl;
    cout << "**************************" << endl;
    cout << endl;
}

//退出系统
void WorkManage::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

//保存文件
void WorkManage::SaveFile()
{
    ofstream ofs;
    ofs.open(EMP_FILE, ios::out); //写入文件内容
    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs << this->m_EmpArray[i]->w_id << " "
            << this->m_EmpArray[i]->w_name << " "
            << this->m_EmpArray[i]->w_deptid << endl;
    }
    ofs.close(); // 关闭文件
}

//读取文件
void ReadFile()
{
    ifstream ifs;
    ifs.open(EMP_FILE, ios::in); // 读取文件内容
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        return;
    }
    while (!ifs.eof())
    {
        int id;
        string name;
        int deptid;
        ifs >> id >> name >> deptid;
        cout << id << " " << name << " " << deptid << endl;
    }
    ifs.close(); // 关闭文件
}

//统计职工人数
int WorkManage::getEmpNum()
{
    ifstream ifs;
    ifs.open(EMP_FILE, ios::in); // 读取文件内容

    int id;
    string name;
    int deptid;

    int count = 0;

    while (ifs >> id && ifs >> name && ifs >> deptid)
    {
        count++;
    }
    ifs.close(); // 关闭文件

    // 文件不为空
    this->m_FileIsEmpty = false;

    return count; // 返回职工人数

}


//添加职工
void WorkManage::AddEmp()
{
    cout << "请输入添加职工数量：" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        int SetSize = this->m_EmpNum + addNum;
        AbstrctWorker **newSpace = new AbstrctWorker*[SetSize];

        if(this->m_EmpArray!=NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }   
        }

        
        cout << "请输入新职工信息" << endl;
        for(int i=0;i<addNum;i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
            cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

            AbstrctWorker *abstrctworker = NULL;

            switch (dSelect)
            {
            case 1: // 普通员工
                abstrctworker = new Employ(id, name, 1);
                break;
            case 2: // 经理
                abstrctworker = new Manager(id, name, 2);
                break;
            case 3: // 老板
                abstrctworker = new Boss(id, name, 3);
                break;
            default:
                break;
            }

            newSpace[this->m_EmpNum + i] = abstrctworker;

        }
        // 释放旧数组并更新指针

        if (this->m_EmpArray != NULL)
        {
            delete[] this->m_EmpArray;
        }
        this->m_EmpArray = newSpace;
        this->m_EmpNum = SetSize;
        
		//更新职工不为空标志
		this->m_FileIsEmpty = false;

        //保存到文件中
        this->SaveFile();
        cout << "成功添加 " << addNum << " 名职工！" << endl;

    }
    else
    {
        cout << "输入数据有误" << endl;
    }
    
    system("pause");
    system("cls");
}

//显示职工
void WorkManage::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
} 

//删除职工
void WorkManage::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号：" << endl;
        int id;
        cin >> id;

        int index = this->IsExist(id); //判断职工是否存在

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->SaveFile(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
    }

    system("pause");
    system("cls");
}

//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkManage::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->w_id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

//修改职工
void WorkManage::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout <<"请输入要修改的职工编号：" << endl;
        int id;
        cin >> id;

        int index = this->IsExist(id); //判断职工是否存在

        if(index != -1)  //说明index上位置数据需要修改
        {
            delete this->m_EmpArray[index]; //释放原有职工对象内存
            this->m_EmpArray[index] = NULL; //将原有职工对象指针置空

            int dSelect= 0;
            
            cout << "查到： " << this->m_EmpArray[index]->w_id << "号职工，请输入新职工号： " << endl;

            cout << "请输入新的职工编号：" << endl;
            int newId;
            cin >> newId;

            cout << "请输入新的职工姓名：" << endl;
            string newName;
            cin >> newName;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;

            cin >> dSelect;
			AbstrctWorker * abstrctworker = NULL;
			switch (dSelect)
			{
			case 1:
                abstrctworker = new Employ(newId, newName, dSelect);
				break;
			case 2:
                abstrctworker = new Manager(newId, newName, dSelect);
				break;
			case 3:
                abstrctworker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
           
            //更改数据 到数组中
			this->m_EmpArray[index]= abstrctworker;

            cout << "修改成功！" << endl;

            //保存到文件中
			this->SaveFile(); //删除后数据同步到文件中

        }
        else
        {
            cout << "修改失败，未找到该职工" << endl;
        }
    }

    system("pause");
    system("cls");
}

//查找职工
void WorkManage::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入要查找的职工编号：" << endl;
        int id;
        cin >> id;

        int index = this->IsExist(id); //判断职工是否存在

        if (index != -1)  //说明index上位置数据需要查找
        {
            this->m_EmpArray[index]->ShowInfo(); //显示职工信息
        }
        else
        {
            cout << "查找失败，未找到该职工" << endl;
        }
    }

    system("pause");
    system("cls");
}

//排序职工
void WorkManage::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请输入排序方式：1.升序 2.降序" << endl;
        int select = 0;
        cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (m_EmpArray[minOrMax]->w_id > m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
				else  //降序
				{
					if (m_EmpArray[minOrMax]->w_id < m_EmpArray[j]->w_id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				AbstrctWorker * temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}

		}
        if (select != 1 && select != 2)
        {
            cout << "输入错误，请输入 1 或 2！" << endl;
            system("pause");
            system("cls");
            return;
        }
        if (m_EmpNum <= 1)
        {
            cout << "职工数量不足，无需排序！" << endl;
            return;
        }   
        
        cout << "职工排序成功！" << endl;
        this->SaveFile(); //保存到文件中
        this->Show_Emp();//显示职工信息
    }

}

//清空文件
void WorkManage::Clean_File()
{
    cout << "确认清空文件吗？" << endl;
    cout << "1.确认清空" << endl;
    cout << "2.取消清空" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(EMP_FILE, ios::trunc); //清空文件内容
        ofs.close(); //关闭文件
        if (this->m_EmpArray != NULL)
		{
            for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
        cout << "文件已清空！" << endl;
    }
    else
    {
        cout << "取消清空！" << endl;
    }
    system("pause");
    system("cls");
}