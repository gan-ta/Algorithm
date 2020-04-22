#include <iostream>
using namespace std;

char screen[3100][6143];
int width[11];

int func(int num);
void divide(int a, int b, int height);

int main()
{
	int N;
	cin >> N;
	int i, j;
	width[0] = 5;
	for (i = 1; i <= 11; i++)
	{
		width[i] = (width[i - 1] * 2) + 1;
	}

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= width[func(N)]; j++)
		{
			screen[i][j] = ' ';
		}
	}

	divide(1, (width[func(N)] + 1) / 2, N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= width[func(N)]; j++)
		{
			cout << screen[i][j];
		}
		cout << endl;
	}


	return 0;
}

int func(int num)
{
	int temp = num / 3;
	if (temp == 0)
	{
		return 0;
	}
	int res = 0;
	while (temp != 1)
	{
		temp = temp / 2;
		res++;
	}
	return res;
}


void divide(int a, int b, int height)
{
	if (height == 3)
	{
		screen[a][b] = '*';
		screen[a + 1][b - 1] = '*';
		screen[a + 1][b + 1] = '*';
		screen[a + 2][b - 2] = '*';
		screen[a + 2][b - 1] = '*';
		screen[a + 2][b] = '*';
		screen[a + 2][b + 1] = '*';
		screen[a + 2][b + 2] = '*';
	}
	else
	{
		divide(a, b, height / 2);
		divide(a + height / 2, b + (width[func(height / 2)] + 1) / 2, height / 2);
		divide(a + height / 2, b - (width[func(height / 2)] + 1) / 2, height / 2);
	}
}