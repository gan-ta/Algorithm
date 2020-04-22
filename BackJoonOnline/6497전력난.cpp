#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef struct info {
	int s;
	int e;
	int w;
	bool operator<(info& i)
	{
		return w < i.w;
	}
}info;

vector<info> map;

int parent[200001];

int m, n;

int find(int x)
{
	if (parent[x] == x) return x;
	return find(parent[x]);

}

void merge(int x, int y)
{
	int s1, s2;
	s1 = find(x);
	s2 = find(y);
	parent[s2] = s1;
}

int main()
{
	int i;
	int total = 0;
	while (1)
	{
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		memset(parent, 0, sizeof(parent));
		map.clear();
		total = 0;

		for (i = 0; i < n; i++)
		{
			info temp;
			cin >> temp.s;
			cin >> temp.e;
			cin >> temp.w;
			total += temp.w;
			map.push_back(temp);
		}

		sort(map.begin(), map.end());

		for (i = 0; i <= m; i++)
		{
			parent[i] = i;
		}

		int count = 0;
		int index = 0;
		int sub = 0;
		while (count < m - 1)
		{
			int s1, s2;
			s1 = find(map[index].s);
			s2 = find(map[index].e);

			if (s1 != s2)
			{
				merge(s1, s2);
				count++;
				sub += map[index].w;
			}
			index++;
		}

		cout << total - sub << endl;

	}
	return 0;
}