#include <cstdio>
using namespace std;

int map[52][52];
int visited[52][52] = { 0, };
int n, m;
int start_r, start_c;
int direction;
int ans= 0;

void count_visited()
{
	int i,j;

	for (i = 1; i <= n ;i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (visited[i][j] == 1)
			{
				ans++;
			}
		}
	}
}



void dfs(int r, int c, int direct)
{
	int nr, nc;
	int new_direct;
	int check = 0;
	

	visited[r][c] = 1;

	while (1)
	{
		check++;
		if (check == 5)
		{
			if (direct == 0)
			{
				nr = r + 1;
				nc = c;
			}
			else if (direct == 1)
			{
				nr = r;
				nc = c + 1;
			}
			else if (direct == 2)
			{
				nr = r - 1;
				nc = c;
			}
			else if (direct == 3)
			{
				nr = r;
				nc = c - 1;
			}

			if (nr >= 0 || nr < n && nc >= 0 || nc < m)
			{
				if (map[nr][nc] != 1)
				{
					check = 0;
					r = nr;
					c = nc;
					continue;
				}
				else
				{
					count_visited();
					break;
				}
			}
			else
			{
				count_visited();
				break;
			}
		}
		if (direct == 0)
		{
			nr = r;
			nc = c - 1;
		}
		else if (direct == 1)
		{
			nr = r + 1;
			nc = c;
		}
		else if (direct == 2)
		{
			nr = r;
			nc = c + 1;

		}
		else if (direct == 3)
		{
			nr = r - 1;
			nc = c;
		}

		if (nr <0  || nr >= n && nc < 0 || nc >= m)
		{

		}

		if (visited[nr][nc] == 0 && map[nr][nc] == 0)
		{
			new_direct = (direct + 1) % 4;
			dfs(nr, nc, new_direct);
			break;

		}
		else
		{
			direct = (direct + 1) % 4;
			continue;
		}
	}

	return;
}

int main()
{
	int i, j;
	
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &start_r, &start_c, &direction);

	if (direction == 1) direction = 3;
	if (direction == 3) direction = 1;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	dfs(start_r, start_c,direction);

	printf("%d\n", ans);

	return 0;
}