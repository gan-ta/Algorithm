#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[1001];

int visited[1001] = { 0, };
int n, m;

queue<int> q;


int main()
{
	int i,j;
	int res = 0;
	int s;
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
			visited[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				s = q.front();
				q.pop();
				for (j = 0; j < map[s].size(); j++)
				{
					if (visited[map[s][j]] == 0)
					{
						visited[map[s][j]] = 1;
						q.push(map[s][j]);
					}
				}
			}
		}
	}
	
	printf("%d\n", res);

	return 0;
}