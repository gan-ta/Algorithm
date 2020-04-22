#include <iostream>
using namespace std;

int pre[51][51];
int res[51][51];

void change(int a, int b);
bool check(int a, int b);

int main()
{
	int n, m;
	int i, j, k, l;
	int r = 0;


	cin >> n >> m;


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &pre[i][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &res[i][j]);
		}
	}

	for (i = 1; i <= n - 2; i++)
	{
		for (j = 1; j <= m - 2; j++)
		{
			if (pre[i][j] != res[i][j])
			{
				change(i, j);
				r++;
			}
		}
	}


	if (!check(n, m))
	{
		cout << -1 << endl;
	}
	else
	{
		cout << r << endl;
	}




	return 0;
}

bool check(int a, int b)
{
	int i, j;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= b; j++)
		{
			if (pre[i][j] != res[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void change(int a, int b)
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			if (pre[a + i][b + j] == 0)
			{
				pre[a + i][b + j] = 1;
			}
			else
			{
				pre[a + i][b + j] = 0;
			}
		}
	}
}

