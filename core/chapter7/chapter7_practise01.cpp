#include <iostream>
using namespace std;

template <class T>  //声明函数模板
//交换函数
void Myswap(T&a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

//降序排列
template <class T>  //声明函数模板
void Mysort(T arr[],int len)
{
	for(int i =0;i<len;i++)
	{
		int max = i;
		for(int j = i + 1; j < len; j++)
        {
            if(arr[j] < arr[max])
            {
                max = j;  // 更新最大值索引
            }
        }
        if(max != i)  // 只有当找到更大值时才交换
        {
            Myswap(arr[i], arr[max]);  // 使用 Myswap 交换
        }
	}
}

template<class T>
void printarr(T arr[],int len)
{
	for (int i =0;i<len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() 
{  	
	char arr[] = "asdfiopu";
	int len = sizeof(arr)/sizeof(arr[0]);
	Mysort(arr,len);
	printarr(arr,len);

	int arr1[] = {6,5,1,4,6,5,1};
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	Mysort(arr1,len1);
	printarr(arr1,len1);
	system("cls");
	return 0;
}
