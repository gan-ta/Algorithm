#include <cstdio>
#include <vector>
using namespace std;

vector<int> map[1001];

int visited[1001] = { 0, };
int n, m;

void dfs(int start)
{
	int i;
	visited[start] = 1;

	for (i = 0; i < map[start].size(); i++)
	{
		if (visited[map[start][i]] == 0)
		{
			dfs(map[start][i]);
		}
	}
}

int main()
{
	int i;
	int res = 0;
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}

	for (i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			res++;
			dfs(i);
		}
	}
	printf("%d\n", res);

	return 0;
}