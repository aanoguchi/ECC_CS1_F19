//Lab 4.23 Fausto Meza

#include <iostream>
using namespace std;

int main()
{
	int i, stars;
	int rows = 3;
	for (i = 1; i <= rows; i++)
	{
		for (stars = 1; stars <= i; stars++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	for (int q = rows; q >= 1; q--)//inverse of the triangle
	{
		for (int j = 1; j <= q; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}



		





	return 0;
}


