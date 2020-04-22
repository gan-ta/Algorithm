#include <stdio.h>

int bfs_search(int n, int k);
int visited[100001] = { 0, };
int q[100001];
int front = -1, rear = -1;

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", bfs_search(a, b));
	return 0;
}

int bfs_search(int n, int k)
{
	q[++rear] = n;
	visited[n] = 1;
	while (front != rear)
	{
		n = q[++front];

		if (n == k)
		{
			return (visited[n] - 1);
		}

		if ((n - 1 >= 0) && (visited[n - 1] == 0))
		{
			q[++rear] = n - 1;
			visited[n - 1] = visited[n] + 1;
		}
		if ((n + 1 <= 100000) && (visited[n + 1] == 0))
		{
			q[++rear] = n + 1;
			visited[n + 1] = visited[n] + 1;
		}
		if ((n * 2 <= 100000) && (visited[2 * n] == 0))
		{
			q[++rear] = 2 * n;
			visited[2 * n] = visited[n] + 1;
		}
	}
}