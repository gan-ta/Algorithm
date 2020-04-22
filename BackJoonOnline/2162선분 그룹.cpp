#include <iostream>
#include <vector>
using namespace std;

typedef struct point {
	long long x;
	long long y;
}point;

typedef struct line {
	long long x1;
	long long y1;
	long long x2;
	long long y2;
}line;



int SA(point a, point b, point c);
int is_intersect(line a, line b);

int get_parent(int p);
void union_parent(int a, int b);

int N;
vector<line> line_group;

int parent[3001] = { 0, };
int line_check[3001] = { 0, };

int main()
{
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		line temp;
		cin >> temp.x1;
		cin >> temp.y1;
		cin >> temp.x2;
		cin >> temp.y2;
		line_group.push_back(temp);
		parent[i] = i;
	}

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (is_intersect(line_group[i], line_group[j]) == 1)
			{
				union_parent(i + 1, j + 1);
			}
		}
	}

	int group_count = 0;
	for (i = 1; i <= N; i++)
	{
		if (parent[i] == i)
		{
			group_count++;
		}
		line_check[get_parent(i)] += 1;
	}

	int line_count = -1;
	for (i = 1; i <= N; i++)
	{
		if (line_count < line_check[get_parent(i)])
		{
			line_count = line_check[get_parent(i)];
		}
	}

	cout << group_count << endl;
	cout << line_count << endl;

	return 0;
}

int get_parent(int a)
{
	if (parent[a] == a)
	{
		return a;
	}

	return get_parent(parent[a]);
}

void union_parent(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);

	if (a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

int SA(point a, point b, point c)
{
	int res;
	res = ((b.x - a.x) * (c.y - a.y)) - ((b.y - a.y) * (c.x - a.x));
	if (res > 0)
	{
		return 1;
	}
	else if (res == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int is_intersect(line a, line b)
{
	point A1;
	point A2;
	point B1;
	point B2;
	long long T1, T2;

	
	A1.x = a.x1;
	A1.y = a.y1;

	A2.x = a.x2;
	A2.y = a.y2;

	B1.x = b.x1;
	B1.y = b.y1;

	B2.x = b.x2;
	B2.y = b.y2;

	
	T1 = SA(A1, A2, B1) * SA(A1, A2, B2);
	T2 = SA(B1, B2, A1) * SA(B1, B2, A2);

	if (T1 == 0 && T2 == 0)
	{
		long long hight1, low1;
		long long hight2, low2;
		
		if (A1.x >= A2.x)
		{
			hight1 = A1.x;
			low1 = A2.x;
		}
		else
		{
			hight1 = A2.x;
			low1 = A1.x;
		}

		
		if (B1.x >= B2.x)
		{
			hight2 = B1.x;
			low2 = B2.x;
		}
		else
		{
			hight2 = B2.x;
			low2 = B1.x;
		}

		
		if (hight2 > hight1)
		{
			if (low2 > hight1)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if (hight2 < hight1)
		{
			if (low1 > hight2)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			
			if (A1.y >= A2.y)
			{
				hight1 = A1.y;
				low1 = A2.y;
			}
			else
			{
				hight1 = A2.y;
				low1 = A1.y;
			}

			
			if (B1.y >= B2.y)
			{
				hight2 = B1.y;
				low2 = B2.y;
			}
			else
			{
				hight2 = B2.y;
				low2 = B1.y;
			}


			
			if (hight2 > hight1)
			{
				if (low2 > hight1)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else if (hight2 < hight1)
			{
				if (low1 > hight2)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
	}
	return T1 <= 0 && T2 <= 0;
}