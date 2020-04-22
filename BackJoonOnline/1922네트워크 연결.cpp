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
int parent[1001] = { 0, };

bool cmp(info a, info b);
void union_parent(int x, int y);
int find_parent(int x);

int N, M;
int main()
{
	int i;
	cin >> N;
	cin >> M;
	for (i = 0; i < M; i++)
	{
		info temp;
		int start, end, weight;
		cin >> start >> end >> weight;
		temp.s = start;
		temp.e = end;
		temp.w = weight;
		map.push_back(temp);
	}

	for (i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	sort(map.begin(), map.end());

	int count = 0;
	int index = 0;
	int res = 0;
	while (count < N - 1)
	{
		info search = map[index];
		int s1, s2;

		s1 = find_parent(search.s);
		s2 = find_parent(search.e);

		if (s1 != s2)
		{
			union_parent(s1, s2);
			count++;
			res += search.w;
		}
		index++;
	}

	cout << res << endl;
	return 0;
}


void union_parent(int x, int y)
{
	if (find_parent(x) < find_parent(y))
	{
		parent[find_parent(y)] = find_parent(x);
	}
	else
	{
		parent[find_parent(x)] = find_parent(y);
	}
}

int find_parent(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return find_parent(parent[x]);
	}
}
