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

	void content()
	{
		cout << "JAVA学科视频" << endl;
	}

};

int main() 
{
	BasePage basePage;
	basePage.header();
	basePage.footer();
	basePage.left();
	basePage.content(); 
	system("cls");
	return 0;
}
