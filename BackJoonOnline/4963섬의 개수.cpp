#include <cstdio>
#include <cstring>
using namespace std;

int map[51][51];
int dr[8] = {1,-1,0,0,1,1,-1,-1};
int dc[8] = {0,0,1,-1,1,-1,1,-1 };
int w, h;


void dfs(int r, int c)
{
	int i;
	int nr, nc;
	map[r][c] = 0;

	for (i = 0; i < 8; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];

		if (nr >= 0 && nr < h && nc >= 0 && nc < w)
		{
			if (map[nr][nc] == 1)
			{
				dfs(nr, nc);
			}
		}
	}
}

int main()
{
	int i, j;
	int res = 0;

	while (1)
	{
		scanf("%d%d", &w, &h);
		res = 0;
		if (w == 0 && h == 0)
		{
			break;
		}

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					dfs(i, j);
					res++;
				}
			}
		}

		memset(map, 0, sizeof(0));

		printf("%d\n", res);
	}

	return 0;
}