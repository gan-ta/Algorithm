#include <iostream>
using namespace std;

char map[65][65];


void print(int r, int c, int n);



int main()
{
	int N;
	int i, j;
	cin >> N;
	char temp;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> temp;
			map[i][j] = temp;
		}
	}

	print(1, 1, N);

	return 0;
}


void print(int r, int c, int n)
{
	char temp;
	temp = map[r][c];
	int i, j;
	int check = 0;
	for (i = r; i <= r + n - 1; i++)
	{
		for (j = c; j <= c + n - 1; j++)
		{
			if (temp != map[i][j])
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			break;
		}
	}
	if (check != 1)
	{
		cout << temp;
	}
	else
	{
		cout << "(";
		print(r, c, n / 2);
		print(r, c + (n / 2), n / 2);
		print(r + (n / 2), c, n / 2);
		print(r + (n / 2), c + (n / 2), n / 2);
		cout << ")";
	}
}