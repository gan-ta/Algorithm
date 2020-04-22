#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26];
int visited[26][26] = { 0, };
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int cnt = 0;
vector<int> apt_cnt;
int n;

void dfs(int sr,int sc)
{
	int i,nr,nc;
	visited[sr][sc] = 1;
	cnt++;

	for (i = 0; i < 4; i++)
	{
		nr = sr + dr[i];
		nc = sc + dc[i];

		if ((0 <= nr) && (nr < n) && (0 <= nc) && (nc < n))
		{
			if ((map[nr][nc] == 1) && (visited[nr][nc] == 0))
			{
				dfs(nr, nc);
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if ((visited[i][j] == 0) && (map[i][j] == 1))
			{
				dfs(i, j);
				apt_cnt.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(apt_cnt.begin(), apt_cnt.end());

	printf("%d\n", apt_cnt.size());
	for (i = 0; i < apt_cnt.size(); i++)
	{
		printf("%d\n", apt_cnt[i]);
	}

	return 0;
}