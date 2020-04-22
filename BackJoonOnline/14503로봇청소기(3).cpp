#include <cstdio>
#include <queue>
using namespace std;

typedef struct robot {
	int r;
	int c;
	int dir;
}robot;

int n, m;
int map[51][51];

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

queue<robot> q;

int main()
{
	int res = 0;
	int sr, sc, sd;
	int i, j;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &sr, &sc, &sd);

	q.push({ sr,sc,sd });

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while (!q.empty())
	{
		robot search;
		robot next;
		search = q.front();
		q.pop();

		if (map[search.r][search.c] == 0)
		{
			map[search.r][search.c] = 2;
			res++;
		}

		for (i = 0; i < 4; i++)
		{
			next.dir = (search.dir + 3 + (i * 3)) % 4;
			next.r = search.r + dr[next.dir];
			next.c = search.c + dc[next.dir];

			if (map[next.r][next.c] != 0)
			{
				continue;
			}
			q.push(next);
			break;
		}

		if (q.empty())
		{
			next.dir = search.dir;
			next.r = search.r + dr[(next.dir+2) % 4];
			next.c = search.c + dc[(next.dir + 2) % 4];

			if (map[next.r][next.c] == 1) break;

			q.push(next);
		}
	}
	printf("%d\n", res);
	return 0;
}
