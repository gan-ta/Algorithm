#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

typedef struct s{
	int r;
	int c;
}s;

int map[101][101];
int marking[101][101];
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
queue<s> q;

int main()
{
	int n, m;
	int i, j;
	int res = 100001;
	s start;
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	start.r = 1;
	start.c = 1;

	q.push(start);
	memset(marking, -1, sizeof(marking));
	marking[1][1] = 0;


	while (!q.empty())
	{
		s search = q.front();
		q.pop();

		if (search.r == m && search.c == n)
		{
			if (res > marking[search.r][search.c])
			{
				res = marking[search.r][search.c];
			}
		}

		for (i = 0; i < 4; i++)
		{
			s insert;
			insert.r = search.r + dr[i];
			insert.c = search.c + dc[i];

			if (insert.r > 0 && insert.r <= m && insert.c > 0 && insert.c <= n)
			{
				if (marking[insert.r][insert.c] == -1)
				{
					if (map[insert.r][insert.c] == 1)
					{
						marking[insert.r][insert.c] = marking[search.r][search.c] + 1;
					}
					else
					{
						marking[insert.r][insert.c] = marking[search.r][search.c];
					}
					q.push(insert);
				}
				else
				{
					if (map[insert.r][insert.c] == 1)
					{
						if (marking[insert.r][insert.c] > marking[search.r][search.c] + 1)
						{
							marking[insert.r][insert.c] = marking[search.r][search.c] + 1;
							q.push(insert);
						}
					}
					else
					{
						if (marking[insert.r][insert.c] > marking[search.r][search.c])
						{
							marking[insert.r][insert.c] = marking[search.r][search.c];
							q.push(insert);
						}
					}
				}
			}

		}

	}

	printf("%d\n", res);
	
	return 0;
}

