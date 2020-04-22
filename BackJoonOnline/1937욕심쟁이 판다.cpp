#include <iostream>
using namespace std;

int map[502][502] = { 0, };
int dp[501][501];

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0 ,1, 0 ,-1 };

int d_temp = 0;

int dfs_search(int r, int c);

int main()
{
	int N;
	cin >> N;
	int i, j;
	int max = -1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = 1;
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			dfs_search(i, j);
		}
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (max < dp[i][j])
			{
				max = dp[i][j];
			}
		}
	}

	cout << max << endl;
	return 0;
}

int dfs_search(int r, int c)
{
	int i;
	int nr, nc;
	int temp;

	for (i = 0; i < 4; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];


		if ((map[nr][nc] == 0) || (map[nr][nc] <= map[r][c]))
		{
			continue;
		}
		else
		{
			if (dp[nr][nc] != 1)
			{
				if (dp[r][c] < dp[nr][nc] + 1)
				{
					dp[r][c] = dp[nr][nc] + 1;
				}
			}
			else
			{
				temp = dfs_search(nr, nc) + 1; 
				if (dp[r][c] < temp)
				{
					dp[r][c] = temp;
				}

			}
		}
	}
	return dp[r][c];
}