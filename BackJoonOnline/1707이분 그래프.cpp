#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int k, v, e;
vector<int> map[20001];
int visited[20001] = {0,};

int ans = 0;

void dfs(int start)
{
	int i;

	for (i = 0; i < map[start].size(); i++)
	{
		if (visited[start] == visited[map[start][i]])
		{
			ans = 1;
			return;
		}
	}

	for (i = 0; i < map[start].size(); i++)
	{
		if (visited[map[start][i]] == 0)
		{
			if (visited[start] == 1)
			{
				visited[map[start][i]] = 2;
			}
			else if (visited[start] == 2)
			{
				visited[map[start][i]] = 1;
			}
			dfs(map[start][i]);
		}
	}
}

int main()
{
	int i,j,k;
	int a, b;
	scanf("%d", &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &v);
		scanf("%d", &e);
		for (j = 0; j < e; j++)
		{
			scanf("%d", &a);
			scanf("%d", &b);

			map[a].push_back(b);
			map[b].push_back(a);
		}

		for (j = 1; j <= v;j++)
		{
			if (visited[j] == 0)
			{
				visited[j] = 1;
				dfs(j);
			}
			if (ans == 1) break;
		}

		if (ans == 0) printf("YES\n");
		else printf("NO\n");
		ans = 0;
		memset(visited, 0, sizeof(visited));
		for (j = 0; j < 20001; j++)
		{
			map[j].clear();
		}
	}
	return 0;
}