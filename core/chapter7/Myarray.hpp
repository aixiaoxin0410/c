#pragma once
#include <iostream>
using namespace std;

template<class T>
class Myarray
{
public:

    Myarray(int capacity)
    {
        cout << "Myarray的有参构造函数" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    Myarray(const Myarray& arr)
    {
        cout << "Myarray的拷贝构造函数" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        // this->pAddress = arr.pAddress;
        // 深拷贝

        this->pAddress = new T[this->m_Capacity];
        for(int i =0;i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

    }

    Myarray &operator=(const Myarray & arr)
    {
        cout << "Myarray的operator=函数" << endl;
        if(this->pAddress!=NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for(int i =0;i<this->m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    
    }

    ~Myarray()
    {
        cout << "Myarray的析构函数" << endl;
        if(this->pAddress!=NULL)
        {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }

    void tail_insert(const T & val)
    {
        if(this->m_Capacity == this->m_Size)
        {
            return;
        }

        this->pAddress[m_Size] = val;
        this->m_Size++;
    }

    void tail_delete()
    {
        if(this->m_Size == 0 )
        {
            return;
        }
        this->m_Size--;
    }

    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    int getcapacity()
    {
        return this->m_Capacity;
    }

    int getsize()
    {
        return this->m_Size;
    }

private:
    T *pAddress;
    int m_Capacity;
    int m_Size;
};