#include <iostream>
using namespace std;

class Cube
{
public:
	int Setlwh(int length, int width, int height)
	{
		m_length = length;
		m_width = width;
		m_height = height;
		return 0;
	}

	int Getl()
	{
		return m_length;
	}

	int Getw()
	{
		return m_width;
	}

	int Geth()
	{
		return m_height;
	}

	void Show()
	{
		cout << "The length, width and height of the cube are: " << m_length << ", " << m_width << ", " << m_height << endl;
	}

	void calculateSurface()
	{
		cout << "The surface area of the cube is: " << 2 * (m_length * m_width + m_width * m_height + m_height * m_length) << endl;
	}

	void calculateVolume()
	{
		cout << "The volume of the cube is: " << m_length * m_width * m_height << endl;
	}

	void same(Cube c)
	{
		if(m_length == c.Getl() && m_width == c.Getw() && m_height == c.Geth())
		{
			cout << "The two cubes are the same." << endl;
		}
		else
		{
			cout << "The two cubes are not the same." << endl;
		}
	}

private:
	int m_length;
	int m_width;
	int m_height;
};


int main() 
{
	Cube cube1;
	cube1.Setlwh(10, 20, 30);
	cube1.Show();
	cube1.calculateSurface();
	cube1.calculateVolume();

	Cube cube2;
	cube2.Setlwh(15, 20, 30);
	cube2.same(cube1);
	system("cls");
	return 0;
}
