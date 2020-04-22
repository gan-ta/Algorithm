#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct point {
	int a;
	int b;
}point;

vector<point> place;

typedef struct edge {
	int s;
	int e;
	double w;
	bool operator<(edge& i)
	{
		return w < i.w;
	}
}edge;

vector<edge> map;
int parent[1001];

int n, m;

int find(int x)
{
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}

void merge(int x, int y)
{
	int temp1, temp2;
	temp1 = find(x);
	temp2 = find(y);
	parent[temp1] = temp2;
}

double dist(point x, point y)
{
	return sqrt(pow(x.a - y.a, 2) + pow(x.b - y.b, 2));
}

int main()
{
	int i, j;
	int count = 0;
	scanf("%d %d", &n, &m);

	for (i = 0; i <= 1000; i++)
	{
		parent[i] = i;
	}

	for (i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		point temp;
		temp.a = x;
		temp.b = y;
		place.push_back(temp);
	}

	for (i = 0; i < m; i++)
	{
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		int x = find(s1);
		int y = find(s2);
		if (x != y)
		{
			merge(x, y);
			count++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			point p1 = place[i];
			point p2 = place[j];
			edge temp;
			temp.s = i + 1;
			temp.e = j + 1;
			temp.w = dist(p1, p2);
			map.push_back(temp);
		}
	}

	sort(map.begin(), map.end());

	double res = 0;
	int index = 0;


	while (count < n - 1)
	{
		edge e = map[index];
		int start, end;
		start = e.s;
		end = e.e;

		if (find(start) != find(end))
		{
			res += e.w;
			merge(start, end);
			count++;
		}
		index++;
	}

	printf("%0.2f", res);
	return 0;
}