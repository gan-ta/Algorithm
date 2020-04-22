#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N, M, K;

vector<int> info[1001];

int visited[1001];
int match[1001];

bool dfs(int a);

int main()
{
	int i, j;
	cin >> N >> M >> K;

	for (i = 0; i < N; i++)
	{
		int num, temp;
		cin >> num;
		for (j = 0; j < num; j++)
		{
			cin >> temp;
			info[i].push_back(temp);
		}
	}

	memset(match, -1, sizeof(int) * 1001);
	int ans = 0;

	for (i = 0; i < N; i++)
	{
		memset(visited, -1, sizeof(visited));
		if (dfs(i))
		{
			ans++;
		}
	}
	int check = 0;

	for (i = 0; i < N; i++)
	{
		memset(visited, -1, sizeof(visited));
		if (dfs(i))
		{
			ans++;
			check++;
		}
		if (check == K)
		{
			break;
		}
	}

	cout << ans << endl;
	return 0;
}

bool dfs(int a)
{
	int i;
	if (visited[a] == 1)
	{
		return false;
	}
	visited[a] = 1;

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