#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef struct pos {
	int x, y;
}pos;

double dist(pos p1, pos p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int N;
pos p[100002];

bool cmp1(pos p1, pos p2) {
	return p1.x < p2.x || ((p1.x == p2.x) && (p1.y < p2.y));
}

double ccw(pos p1, pos p2, pos p3) {
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool cmp2(pos p1, pos p2) {
	double c = ccw(p[0], p1, p2);
	if (c > 0) return 1;
	if (c < 0) return 0;
	else
	{
		if (dist(p[0], p1) < dist(p[0], p2)) return 1;
		else return 0;
	}
}

int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	sort(p, p + N, cmp1);
	sort(p + 1, p + N, cmp2);

	vector<pos> v;
	v.push_back(p[0]);
	v.push_back(p[1]);

	for (i = 2; i < N; i++)
	{
		while (v.size() >= 2 && ccw(v[v.size() - 2], v.back(), p[i]) <= 0) {
			v.pop_back();
		}
		v.push_back(p[i]);
	}

	double ans = -1;
	int size = v.size();
	int j = 1;
	for (i = 0; i < size; i++)
	{
		while (abs(ccw(v[i], v[(i + 1) % size], v[j % size])) < abs(ccw(v[i], v[(i + 1) % size], v[(j + 1) % size])))
		{
			j = (j + 1) % size;
		}
		
		double d = dist(v[i], v[j]);
		if (ans < d)
		{
			ans = d;
		}
	}
	cout.precision(10);
	cout << ans << endl;
	return 0;
}