#include <cstdio>
#include <vector>
using namespace std;

int num_storage[10001] = {0,};
int num_cnt[10001] = {0,};

int n, m;
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

	for (i = 1; i < 10001; i++)
	{
		if (num_storage[i] > num_cnt[i])
		{
			num_cnt[i]++;
			v.push_back(i);
			dfs(depth + 1);
			v.pop_back();
			num_cnt[i]--;
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
		num_storage[num]++;
	}

	dfs(0);

	return 0;
}