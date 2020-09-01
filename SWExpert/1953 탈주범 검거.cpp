#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int visited[51][51];
int map[51][51];
int n, m, r, c, l;

typedef struct info {
	int r;
	int c;
	int status;
}info;

queue<info> q;


void des_down(int r, int c)
{
	int nr = r + 1;
	int nc = c;

	if (nr >= 0 && nr < n && nc >= 0 && nc < m)
	{
		if (visited[nr][nc] == 0 && (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 4 || map[nr][nc] == 7))
		{
			visited[nr][nc] = 1;
			q.push({ nr,nc,map[nr][nc] });
		}
	}
}

void des_up(int r, int c)
{
	int nr = r - 1;
	int nc = c;

	if (nr >= 0 && nr < n && nc >= 0 && nc < m)
	{
		if (visited[nr][nc] == 0 && (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 5 || map[nr][nc] == 6))
		{
			visited[nr][nc] = 1;
			q.push({ nr,nc,map[nr][nc] });
		}
	}
}

void des_right(int r, int c)
{
	int nr = r;
	int nc = c + 1;

	if (nr >= 0 && nr < n && nc >= 0 && nc < m)
	{
		if (visited[nr][nc] == 0 && (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 6 || map[nr][nc] == 7))
		{
			visited[nr][nc] = 1;
			q.push({ nr,nc,map[nr][nc] });
		}
	}
}

void des_left(int r, int c)
{
	int nr = r;
	int nc = c - 1;

	if (nr >= 0 && nr < n && nc >= 0 && nc < m)
	{
		if (visited[nr][nc] == 0 && (map[nr][nc] == 1 || map[nr][nc] == 3 || map[nr][nc] == 4 || map[nr][nc] == 5))
		{
			visited[nr][nc] = 1;
			q.push({ nr,nc,map[nr][nc] });
		}
	}
}

int main()
{
	int T;
	int t, i, j;
	int temp;
	int q_size;
	int nr, nc;
	info search;
	int res = 0;

	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{

		//값의 초기화 작업
		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		while (!q.empty()) q.pop();
		res = 0;

		//맵을 설정
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &temp);
				map[i][j] = temp;
			}
		}

		q.push({ r,c,map[r][c] });
		visited[r][c] = 1;

		//시간만큼 큐를 돌려줌
		for (i = 0; i < l - 1; i++)
		{
			q_size = q.size();

			for (j = 0; j < q_size; j++)
			{
				search = q.front();
				q.pop();

				//케이스 분류의 과정
				if (search.status == 1)
				{
					des_down(search.r, search.c);
					des_up(search.r, search.c);
					des_right(search.r, search.c);
					des_left(search.r, search.c);

				}
				else if (search.status == 2)
				{
					des_down(search.r, search.c);
					des_up(search.r, search.c);
				}
				else if (search.status == 3)
				{
					des_right(search.r, search.c);
					des_left(search.r, search.c);
				}
				else if (search.status == 4)
				{
					des_up(search.r, search.c);
					des_right(search.r, search.c);
				}
				else if (search.status == 5)
				{
					des_right(search.r, search.c);
					des_down(search.r, search.c);
				}
				else if (search.status == 6)
				{
					des_left(search.r, search.c);
					des_down(search.r, search.c);
				}
				else if (search.status == 7)
				{
					des_left(search.r, search.c);
					des_up(search.r, search.c);
				}

			}
		}

		/*for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				printf("%d ", visited[i][j]);
			}
			printf("\n");
		}*/

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (visited[i][j] == 1) res++;
			}
		}

		printf("#%d %d\n", t + 1, res);

	}


	return 0;
}