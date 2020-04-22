#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> result_dfs;
vector<int> result_bfs;
queue<int> q;

int visited[1001] = { 0, };
int map[1001][1001] = { 0, };

int n, m, v;

void dfs(int start)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if ((visited[i] == 0) && (map[start][i] == 1))
		{
			visited[i] = 1;
			result_dfs.push_back(i);
			dfs(i);
		}
	}
}

int main()
{
	int i;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &v);

	for (i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);

		map[a][b] = 1;
		map[b][a] = 1;
	}

	//dfs
	result_dfs.push_back(v);
	visited[v] = 1;
	dfs(v);
	visited[v] = 0;

	memset(visited, 0, sizeof(visited));

	//bfs
	result_bfs.push_back(v);
	q.push(v);
	while (!q.empty())
	{
		int ou = q.front();
		q.pop();
		visited[ou] = 1;
		for (i = 1; i <= n; i++)
		{
			if ((visited[i] == 0) && (map[ou][i] == 1))
			{
				visited[i] = 1;
				result_bfs.push_back(i);
				q.push(i);
			}
		}
	}

	for (i = 0; i < result_dfs.size(); i++)
	{
		printf("%d ", result_dfs[i]);
	}
	printf("\n");
	for (i = 0; i < result_bfs.size(); i++)
	{
		printf("%d ", result_bfs[i]);
	}
	printf("\n");

	return 0;
}