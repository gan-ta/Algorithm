#include <cstdio>
#include <queue>
using namespace std;

typedef struct robot {
	int y;
	int x;
	int dir;
}robot;

int n, m;
int map[50][50];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

robot start;

int main()
{
	int res = 0;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &start.y, &start.x, &start.dir);

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			scanf("%d", &map[y][x]);
		}
	}

	queue <robot> q;
	q.push(start);

	while (!q.empty())
	{
		robot cur = q.front();
		q.pop();
		if (map[cur.y][cur.x] == 0)
		{
			map[cur.y][cur.x] = 2;
			res++;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			robot next;
			next.dir = (cur.dir + 3 - dir) % 4;
			next.y = cur.y + dy[next.dir];
			next.x = cur.x + dx[next.dir];

			if(next.y <  0 || next.y >= n || next.x <0 || next.x >= m || map[next.y][next.x] != 0)
			{
				continue;
			}

			q.push(next);
			break;
		}

		if (q.empty())
		{
			robot next;
			next.dir = cur.dir;
			next.y = cur.y + dy[(next.dir+2) % 4];
			next.x = cur.x + dx[(next.dir+2) % 4];

			if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1)
			{
				break;
			}
			q.push(next);
		}
	}

	printf("%d\n", res);
	return 0;
}
