#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

typedef struct info {
	int s;
	int e;
	int w;
}info;

int dist[501];

vector<info> map;

int N, M;

int main()
{
	int i, j;

	cin >> N >> M;

	for (i = 0; i < M; i++)
	{
		info temp;
		cin >> temp.s;
		cin >> temp.e;
		cin >> temp.w;

		map.push_back(temp);
	}

	for (i = 2; i <= N; i++)
	{
		dist[i] = INF;
	}

	dist[1] = 0;

	for (i = 0; i < N - 1; i++)
	{
		for (j = 0; j < map.size(); j++)
		{
			if (dist[map[j].s] != INF && dist[map[j].s] + map[j].w < dist[map[j].e])
			{
				dist[map[j].e] = dist[map[j].s] + map[j].w;
			}
		}

	}

	int check = 0;
	for (j = 0; j < map.size(); j++)
	{
		if (dist[map[j].s] != INF && dist[map[j].s] + map[j].w < dist[map[j].e])
		{
			check = 1;
		}
	}

	if (check == 1)
	{
		cout << -1 << endl;
	}
	else
	{
		for (i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << dist[i] << endl;
			}
		}
	}

	return 0;
}

