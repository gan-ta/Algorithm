#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct info {
	int x;
	int y;
}INFO;

INFO arr[3];

void print();

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		cin >> arr[i].x >> arr[i].y;
	}
	print();

	return 0;
}

void print()
{

	if (arr[0].y == arr[1].y)
	{
		if (arr[1].y == arr[2].y)
		{
			cout << "WHERE IS MY CHICKEN?" << endl;
			return;

		}
	}
	else if (arr[0].x == arr[1].x) 
	{
		if (arr[1].x == arr[2].x)
		{
			cout << "WHERE IS MY CHICKEN?" << endl;
			return;

		}
	}

	if ((arr[0].x * arr[1].y) == (arr[0].y * arr[1].x))
	{
		if ((arr[0].x * arr[2].y) == (arr[0].y * arr[2].x))
		{
			cout << "WHERE IS MY CHICKEN?" << endl;
			return;
		}
	}

	if (abs(arr[0].x - arr[1].x) == abs(arr[0].y - arr[1].y))
	{
		if (abs(arr[0].x - arr[2].x) == abs(arr[0].y - arr[2].y))
		{
			cout << "WHERE IS MY CHICKEN ? " << endl;
			return;
		}
	}

	cout << "WINNER WINNER CHICKEN DINNER!" << endl;
	return;
}