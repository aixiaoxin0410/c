#include <iostream>
using namespace std;

class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};

class Java : public BasePage
{
public:
	void content()
	{
		cout << "JAVA学科视频" << endl;
	}
};

class Python : public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};

int main() 
{
	cout << "Java下载视频页面如下： " << endl;
	Java java;
	java.header();
	java.footer();
	java.left();
	java.content();

	cout << "Python下载视频页面如下： " << endl;
	Python python;
	python.header();
	python.footer();
	python.left();
	python.content();

	system("cls");
	return 0;
}
