#include <iostream>
using namespace std;

int map[51][51] = { 0, };
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
int cnt = 0;
void dfs(int a, int b);
int m, n;

int main()
{
	int t;
	int k;
	int i, j, l;
	int x, y;

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> m >> n >> k;
		cnt = 0;


		for (j = 0; j < k; j++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (j = 0; j < n; j++)
		{
			for (l = 0; l < m; l++)
			{

				if (map[j][l] == 1)
				{
					cnt++;
					dfs(j, l);
				}
			}
		}

		cout << cnt << endl;
	}

	return 0;
}


void dfs(int a, int b)
{
	int i;
	int x, y;
	map[a][b] = 0;

	for (i = 0; i < 4; i++)
	{
		y = dr[i] + a;
		x = dc[i] + b;

		
		if (map[y][x] == 1 && y >= 0 && y < n && x >= 0 && x < m)
		{
			dfs(y, x);
		}
	}
}