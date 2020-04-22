#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> info[201];

bool visited[201];
int match[201];

int n, m;

bool dfs(int a);

int main()
{
	int i, j;
	cin >> n >> m;

	for (i = 1; i <= n; i++)
	{
		int num, temp;
		cin >> num;
		for (j = 0; j < num; j++)
		{
			cin >> temp;
			info[i].push_back(temp);
		}
	}

	memset(match, -1, sizeof(match));
	int ans = 0;


	for (i = 1; i <= n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
		{
			ans++;
		}
	}


	cout << ans << endl;
	return 0;
}

bool dfs(int a)
{
	int i;
	if (visited[a])
	{
		return false;
	}

	visited[a] = true;

	for (i = 0; i < info[a].size(); i++)
	{
		if (match[info[a][i]] == -1)
		{
			match[info[a][i]] = a;
			return true;
		}
	}

	for (i = 0; i < info[a].size(); i++)
	{
		if (dfs(match[info[a][i]]))
		{
			match[info[a][i]] = a;
			return true;
		}
	}

	return false;
}