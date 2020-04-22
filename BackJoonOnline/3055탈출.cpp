#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

char map[51][51];
int water_visited[51][51] = {0,};
int visited[51][51] = {0,};
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };


typedef struct location {
	int r;
	int c;
}location;

typedef struct w_fill {
	int r;
	int c;
}w_fill;

queue<location> q;
queue<w_fill> wq;


int main()
{
	int i, j;
	int n, m;
	int res = 2501;

	scanf("%d", &n);
	scanf("%d", &m);

	memset(water_visited, -1, sizeof(water_visited));
	memset(visited, -1, sizeof(visited));

	

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%c", &map[i][j]);
			if (map[i][j] == '\n')
			{
				j--;
				continue;
			}

			if (map[i][j] == '*')
			{
				w_fill insert;
				insert.r = i;
				insert.c = j;
				water_visited[i][j] = 0;
				wq.push(insert);
			}

			if (map[i][j] == 'S')
			{
				location insert;
				insert.r = i;
				insert.c = j;
				visited[i][j] = 0;
				q.push(insert);
			}
		}
	}
	

	while (!wq.empty())
	{
		int nr, nc;
		w_fill search;
		w_fill insert;
		search = wq.front();
		wq.pop();

		for (i = 0; i < 4; i++)
		{
			nr = search.r + dr[i];
			nc = search.c + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (map[nr][nc] != 'X' && map[nr][nc] != 'D')
				{
					if (water_visited[nr][nc] == -1)
					{
						insert.r = nr;
						insert.c = nc;
						water_visited[nr][nc] = water_visited[search.r][search.c] + 1;
						wq.push(insert);
					}
					else
					{
						insert.r = nr;
						insert.c = nc;
						if (water_visited[nr][nc] > water_visited[search.r][search.c] + 1)
						{
							water_visited[nr][nc] = water_visited[search.r][search.c] + 1;
							wq.push(insert);
						}
					}
				}
			}
		}
	}

	while (!q.empty())
	{
		int nr, nc;
		location search;
		location insert;
		search = q.front();
		q.pop();

		if (map[search.r][search.c] == 'D')
		{
			if (res > visited[search.r][search.c])
			{
				res = visited[search.r][search.c];
			}
			break;
		}

		for (i = 0; i < 4; i++)
		{
			nr = search.r + dr[i];
			nc = search.c + dc[i];

			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (visited[nr][nc] == -1 && map[nr][nc] != 'X')
				{
					insert.r = nr;
					insert.c = nc;
					if (water_visited[insert.r][insert.c] == -1)
					{
						visited[insert.r][insert.c] = visited[search.r][search.c] + 1;
						q.push(insert);
					}
					else if (water_visited[insert.r][insert.c] > visited[search.r][search.c] + 1)
					{
						visited[insert.r][insert.c] = visited[search.r][search.c] + 1;
						q.push(insert);
					}
				}
				else if(visited[nr][nc] != -1 && map[nr][nc] != 'X')
				{
					insert.r = nr;
					insert.c = nc;
					if (water_visited[insert.r][insert.c] == -1 && (visited[insert.r][insert.c] > visited[search.r][search.c] + 1))
					{
						visited[insert.r][insert.c] = visited[search.r][search.c] + 1;
						q.push(insert);
					}
					else if ((water_visited[insert.r][insert.c] > visited[search.r][search.c] + 1) && (visited[insert.r][insert.c] > visited[search.r][search.c] + 1))
					{
						visited[insert.r][insert.c] = visited[search.r][search.c] + 1;
						q.push(insert);
					}
				}
			}
		}
	}

	if (res == 2501)
	{
		printf("KAKTUS\n");
	}
	else
	{
		printf("%d\n", res);
	}

	return 0;
}