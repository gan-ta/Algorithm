#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int tc, n, m;

stack<int> s;
vector<int> map[100002];
int visited[100002] = { 0, };

void dfs1(int a);
void dfs2(int a);


int main()
{
	int i, j;
	cin >> tc;
	for (j = 0; j < tc; j++)
	{
		cin >> n;
		cin >> m;
		memset(visited, 0, sizeof(visited));
		for (i = 0; i <= n; i++)
		{
			map[i].clear();
		}
		
		for (i = 0; i < m; i++)
		{
			int start, end;
			cin >> start;
			cin >> end;
			map[start].push_back(end);
		}

		for (i = 1; i <= n; i++)
		{
			if (visited[i] == 1)continue;
			dfs1(i);
		}

		memset(visited, 0, sizeof(visited));

		int res = 0;
		while (!s.empty())
		{
			int search = s.top();
			s.pop();
			if (visited[search] == 0)
			{
				dfs2(search);
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}

void dfs1(int a)
{
	int i;
	if (visited[a] == 1) return;
	visited[a] = 1;
	for (i = 0; i < map[a].size(); i++)
	{
		if (visited[map[a][i]] == 1) continue;
		dfs1(map[a][i]);
	}
	s.push(a);
}

void dfs2(int a)
{
	int i;
	if (visited[a] == 1) return;
	visited[a] = 1;
	for (i = 0; i < map[a].size(); i++)
	{
		if (visited[map[a][i]] == 1) continue;
		dfs2(map[a][i]);
	}
}