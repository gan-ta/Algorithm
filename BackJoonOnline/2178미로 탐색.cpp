#include <stdio.h>

int map[101][101];

int minV = 100000;

int visited[101][101] = { 0, };

int dr[] = { 1,0, -1, 0 };
int dc[] = { 0 ,1, 0 , -1 };

//큐의 재료
int q[20000];
int front = -1, rear = -1;

int bfs_find(int N, int M);


int main(void)
{
	int N, M;
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", bfs_find(N, M));

	return 0;
}

int bfs_find(int N, int M)
{
	int i;
	int r;
	int c;
	q[++rear] = 1;
	q[++rear] = 1;
	visited[1][1] = 1;

	while (front != rear)
	{
		r = q[++front];
		c = q[++front];

		if ((r == N) && (c == M))
		{
			return visited[r][c];
		}
		for (i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if ((map[nr][nc] == 1) && (visited[nr][nc] == 0) && (nr >= 1) && (nr <= N) && (nc >= 1) && (nc <= M))
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;
			}
		}
	}
	return 0;
}