#include <cstdio>
#include <vector>
using namespace std;

int num_storage[10001] = { 0, };

int n, m;
int max_num = -1;
vector<int> v;

void Print()
{
	int i;
	for (i = 0; i < v.size(); i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");

}

void dfs(int depth)
{
	int i;
	if (depth == m)
	{
		Print();
		return;
	}

	for (i = 1; i <= max_num; i++)
	{
		if (num_storage[i] == 1)
		{
			v.push_back(i);
			dfs(depth + 1);
			v.pop_back();
		}
	}
}

int main()
{
	int i;
	int num;
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (max_num < num)
		{
			max_num = num;
		}
		num_storage[num] = 1;
	}

	for (i = 1; i <= max_num; i++)
	{
		if (num_storage[i] == 1)
		{
			v.push_back(i);
			dfs(1);
			v.pop_back();
		}
	}

	return 0;
}