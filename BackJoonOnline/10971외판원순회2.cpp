#include <cstdio>
#include <algorithm>
using namespace std;

int city[15][15];
int visited[15];
int n;
int Min = 99999999;

int check()
{
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}

	return 1;
}

void dfs(int sum, int start, int arrive)
{
	int i;

	if (check() == 1)
	{
		if (city[start][arrive] != 0)
		{
			sum += city[start][arrive];

			if (sum < Min)
			{
				Min = sum;
			}
		}
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (city[start][i] != 0 && visited[i] == 0)
		{
			visited[i] = 1;
			dfs(sum + city[start][i], i, arrive);
			visited[i] = 0;
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &city[i][j]);
		}
	}

	for (i = 1; i <= n; i++)
	{
		visited[i] = 1;
		dfs(0, i, i);
		visited[i] = 0;
	}

	printf("%d\n", Min);
	return 0;
}