#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int length[501];
int temp_length[501];
int predecessor[501] = { 0, };

typedef struct info {
	int s;
	int e;
	int w;
}info;

vector<info> map;
#define INF 100000

int main()
{
	int i, j;
	int TC;
	int N, M, W;
	int start, end, weight;
	cin >> TC;
	for (i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		for (j = 0; j < M; j++)
		{
			info temp;
			cin >> start >> end >> weight;
			temp.s = start;
			temp.e = end;
			temp.w = weight;
			map.push_back(temp);
			temp.s = end;
			temp.e = start;
			map.push_back(temp);
		}
		for (j = 0; j < W; j++)
		{
			info temp;
			cin >> start >> end >> weight;
			weight = -1 * weight;
			temp.s = start;
			temp.e = end;
			temp.w = weight;
			map.push_back(temp);
		}

		memset(length, INF, sizeof(length));
		memset(temp_length, INF, sizeof(temp_length));
		length[1] = 0;
		temp_length[1] = 0;

		int count = 0;
		while (count < M + W - 1)
		{
			for (j = 0; j < map.size(); j++)
			{
				if (length[map[j].s] + map[j].w < length[map[j].e])
				{
					temp_length[map[j].e] = length[map[j].s] + map[j].w;
					predecessor[map[j].e] = map[j].s;
				}
			}

			for (j = 0; j <= N; j++)
			{
				length[j] = temp_length[j];
			}
			count++;

		}

		int check = 0;
		for (j = 0; j < map.size(); j++)
		{
			if (length[map[j].s] + map[j].w < length[map[j].e])
			{
				check = 1;
				break;
			}
		}

		if (check == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		map.clear();

	}
	return 0;
}