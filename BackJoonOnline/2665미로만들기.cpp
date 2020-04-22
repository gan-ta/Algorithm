#include <iostream>
#include <cstdio>
using namespace std;

#define INF 500000


int map[51][51];

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };

void dfs(int r, int c, int count);
int black[51][51] = { 0 };
int n;
int res = 500000;

int main()
{
	int c, i, j;
	scanf("%d", &n);
	
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%1d", &c);
			map[i][j] = c;
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			black[i][j] = INF;
		}
	}


	dfs(1, 1, 0);

	printf("%d\n", res);

	return 0;
}


void dfs(int r, int c, int count)
{
	int i;
	int nr, nc;
	if ((r == n) && (c == n))
	{
		if (res > count)
		{
			res = count;
		}
	}
	else
	{
		for (i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];

			if ((nr > 0) && (nr <= n) && (nc > 0) && (nc <= n))
			{
				if (map[nr][nc] == 0)
				{
					if (black[nr][nc] > count + 1)
					{
						black[nr][nc] = count + 1;
						dfs(nr, nc, count + 1);
					}

				}
				else if (map[nr][nc] == 1)
				{
					if (black[nr][nc] > count)
					{
						black[nr][nc] = count;
						dfs(nr, nc, count);
					}
				}
			}
		}
	}
}