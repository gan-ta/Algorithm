#include <cstdio>
#include <vector>
using namespace std;

int n, m;
int visited[2004] = { 0, };
int ans = 0;

vector<int> map[2004];

void dfs(int start, int depth)
{

	int i;
	if (depth == 5)
	{
		ans = 1;
		return;
	}

	visited[start] = 1;
	for (i = 0; i < map[start].size(); i++)
	{
		if (visited[map[start][i]] == 0)
		{
			dfs(map[start][i], depth + 1);
		}
	}
	visited[start] = 0;
	return;
}

int main()
{
	int i;
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

	for (i = 0; i < n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i, 1);
		}
		if (ans == 1) break;
	}
	
	printf("%d\n", ans);
	return 0;
}