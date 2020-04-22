#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct info {
	int s;
	int e;
	int w;
	bool operator<(info& e) {
		return w < e.w;
	}
}info;

vector<info> map;
int parent[100001];

int find(int x);
void merge(int x, int y);

int main()
{
	int i, j;
	int n, m;
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		info temp;
		cin >> temp.s;
		cin >> temp.e;
		cin >> temp.w;
		map.push_back(temp);
	}

	sort(map.begin(), map.end());

	for (i = 1; i <= 100000; i++)
	{
		parent[i] = i;
	}

	int check = 0;
	int index = 0;
	int res = 0;
	while (check < n - 2)
	{
		info search = map[index];
		int s1, s2;
		s1 = search.s;
		s2 = search.e;
		if (find(s1) != find(s2))
		{
			check++;
			res += search.w;
			merge(s1, s2);
		}
		index++;
	}

	cout << res << endl;
	return 0;
}

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return find(parent[x]);
	}
}

void merge(int x, int y)
{
	if (find(x) < find(y))
	{
		parent[find(y)] = parent[find(x)];
	}
	else
	{
		parent[find(x)] = parent[find(y)];
	}
}
