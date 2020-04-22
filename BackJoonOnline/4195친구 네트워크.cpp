#include <cstdio>
#include <vector>
#include <map>
#include <string>
using namespace std;

int parent[200002];
int friend_num[200002];
char f1[21], f2[21];

int n;


int find(int x)
{
	if (parent[x] == x) return x;
	return find(parent[x]);
}

int merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
	{
		parent[x] = y;
		friend_num[y] += friend_num[x];
		friend_num[x] = 1;
	}
	return friend_num[y];
}

int main()
{
	int t;
	scanf("%d", &t);
	int i, j, k;

	for (k = 0; k < t; k++)
	{
		int count = 1;

		map<string, int> friend_set;
		scanf("%d", &n);

		for (i = 1; i <= (2 * n); i++)
		{
			parent[i] = i;
			friend_num[i] = 1;
		}


		for (i = 0; i < n; i++)
		{
			scanf("%s %s", &f1, &f2);

			if (friend_set.count(f1) == 0)
			{
				friend_set[f1] = count++;
			}

			if (friend_set.count(f2) == 0)
			{
				friend_set[f2] = count++;
			}

			printf("%d\n", merge(friend_set[f1], friend_set[f2]));
		}
	}
	return 0;
}