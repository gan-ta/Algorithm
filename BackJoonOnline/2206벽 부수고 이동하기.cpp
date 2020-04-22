#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef struct location {
	int r;
	int c;
	int dist;
	int crush;
}location;

int map[1001][1001];
int marking1[1001][1001];
int marking2[1001][1001];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

queue<location> q;

int main()
{
	int n, m;
	int i, j;
	int res = 1000001;
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	memset(marking1, -1, sizeof(marking1));
	memset(marking2, -1, sizeof(marking2));

	location start;
	start.r = 1;
	start.c = 1;
	start.dist = 1;
	start.crush = 0;

	marking1[1][1] = 1;

	q.push(start);

	while (!q.empty())
	{
		location search,insert;
		search = q.front();
		q.pop();

		if (search.r == n && search.c == m)
		{
			if (res > search.dist)
			{
				res = search.dist;
			}
		}

		for (i = 0; i < 4; i++)
		{
			insert.r = search.r + dr[i];
			insert.c = search.c + dc[i];
			insert.dist = search.dist + 1;
			if (insert.r > 0 && insert.r <= n && insert.c > 0 && insert.c <= m)
			{
				if (map[insert.r][insert.c] == 1)
				{
					insert.crush = search.crush + 1;
				}
				else
				{
					insert.crush = search.crush;
				}

				if (insert.crush == 0)
				{
					if (marking1[insert.r][insert.c] == -1)
					{
						marking1[insert.r][insert.c] = insert.dist;
						q.push(insert);
					}
					else
					{
						if (marking1[insert.r][insert.c] > insert.dist)
						{
							marking1[insert.r][insert.c] = insert.dist;
							q.push(insert);
						}
					}
				}
				else if (insert.crush == 1)
				{
					if (marking2[insert.r][insert.c] == -1)
					{
						marking2[insert.r][insert.c] = insert.dist;
						q.push(insert);
					}
					else
					{
						if (marking2[insert.r][insert.c] > insert.dist)
						{
							marking2[insert.r][insert.c] = insert.dist;
							q.push(insert);
						}
					}
				}
			}
		}
	}

	if (res == 1000001) printf("%d\n", -1);
	else printf("%d\n", res);

	return 0;
}