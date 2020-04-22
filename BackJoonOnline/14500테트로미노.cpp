#include <cstdio>
#include <algorithm>
using namespace std;


int n, m;

int map[500][500];
int visited[500][500] = { 0, };

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };


int dfs(int r, int c, int count)
{
	if (count == 5) return 0;

	int ans = 0;

	int i;

	for (i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (0 <= nr && nr < n && 0 <= nc && nc < m)
		{
			if (visited[nr][nc] == 0)
			{
				visited[nr][nc] = 1;
				ans = max(ans, dfs(nr, nc, count + 1) + map[r][c]);
				visited[nr][nc] = 0;
			}
		}
	}

	return ans;
}

int ex(int x, int y)
{
	int ans = 0;
	//ㅗ모양
	if (x >= 1 && y >= 1 && y < m - 1)
		ans = max(ans, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	// ㅜ모양
	if (x < n - 1 && y >= 1 && y < m - 1)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]);
	// ㅏ모양
	if (x < n - 1 && x >= 1 && y < m - 1)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x - 1][y] + map[x][y + 1]);
	// ㅓ모양
	if (x < n - 1 && x >= 1 && y >= 1)
		ans = max(ans, map[x][y] + map[x + 1][y] + map[x - 1][y] + map[x][y - 1]);
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);

	int i, j;
	int ans = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			ans = max(ans, dfs(i, j, 1));
			ans = max(ans, ex(i, j));
			visited[i][j] = 0;
		}
	}

	printf("%d\n", ans);

	return 0;
}