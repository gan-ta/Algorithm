#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000

int map[1001][1001] = { 0, };
int reverse_map[1001][1001] = { 0, };

int len[1001] = { 0, };
int reverse_len[1001] = { 0, };

int dist1[1001] = { 0, };
int dist2[1001] = { 0, };


int n, m, source;
int vnear;

int main()
{
	int i, j;
	cin >> n >> m >> source;

	
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			map[i][j] = INF;
			reverse_map[i][j] = INF;
		}
	}
	for (i = 0; i < m; i++)
	{
		int s, e, w;
		cin >> s;
		cin >> e;
		cin >> w;
		map[s][e] = w;
		reverse_map[e][s] = w;
	}

	for (i = 1; i <= n; i++)
	{
		if (i == source)
		{
			continue;
		}
		len[i] = map[source][i];
		reverse_len[i] = reverse_map[source][i];
	}

	
	for (i = 1; i <= n - 1; i++)
	{
		int min = INF;
		for (j = 1; j <= n; j++)
		{
			if (j == source)
			{
				continue;
			}

			if ((0 < len[j]) && (len[j] < min))
			{
				min = len[j];
				vnear = j;
			}
		}

		dist1[vnear] = min;
		for (j = 1; j <= n; j++)
		{
			if (j == source)
			{
				continue;
			}

			if (len[vnear] + map[vnear][j] < len[j])
			{
				len[j] = len[vnear] + map[vnear][j];
			}
		}
		len[vnear] = -1;
	}

	
	for (i = 1; i <= n - 1; i++)
	{
		int min = INF;
		for (j = 1; j <= n; j++)
		{
			if (j == source)
			{
				continue;
			}

			if ((0 < reverse_len[j]) && (reverse_len[j] < min))
			{
				min = reverse_len[j];
				vnear = j;
			}
		}
		dist2[vnear] = min;
		for (j = 1; j <= n; j++)
		{
			if (j == source)
			{
				continue;
			}

			if (reverse_len[vnear] + reverse_map[vnear][j] < reverse_len[j])
			{
				reverse_len[j] = reverse_len[vnear] + reverse_map[vnear][j];
			}
		}
		reverse_len[vnear] = -1;
	}

	int ans = -1;
	for (i = 1; i <= n; i++)
	{
		if (i == source)
		{
			continue;
		}
		if (ans < dist1[i] + dist2[i])
		{
			ans = dist1[i] + dist2[i];
		}
	}
	cout << ans << endl;
	return 0;
}