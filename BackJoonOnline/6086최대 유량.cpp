#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int parent[52] = { 0, };
queue<int>  q;

int capacity[52][52] = { 0, };
int flow[52][52] = { 0, };

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char s, e;
		int start, end, w;
		cin >> s;
		cin >> e;
		cin >> w;

		if ((s >= 65) && (s <= 90))
		{
			start = (int)s - 65;
		}
		else
		{
			start = (int)s - 71;
		}

		if ((e >= 65) && (e <= 90))
		{
			end = (int)e - 65;
		}
		else
		{
			end = (int)e - 71;
		}

		
		capacity[start][end] += w;
		capacity[end][start] += w;
	}

	int res = 0;

	while (1)
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			q.pop();
		}
		memset(parent, -1, sizeof(parent));

		q.push(0);

		while (!q.empty())
		{
			if (parent[25] != -1)
			{
				break;
			}

			int start = q.front();
			q.pop();

			for (int i = 0; i < 52; i++)
			{
				int end;
				end = i;

				if (capacity[start][end] - flow[start][end] > 0 && parent[end] == -1)
				{
					q.push(end);
					parent[end] = start;
				}
			}
		}

		if (parent[25] == -1)
		{
			break;
		}

		int minv = 1100;
		int search = 25;
		while (search != 0)
		{
			if (minv > capacity[parent[search]][search] - flow[parent[search]][search])
			{
				minv = capacity[parent[search]][search] - flow[parent[search]][search];
			}
			search = parent[search];
		}

		search = 25;
		while (search != 0)
		{
			flow[parent[search]][search] += minv;
			flow[search][parent[search]] -= minv;
			search = parent[search];
		}

		res += minv;
	}

	cout << res << endl;
	return 0;
}