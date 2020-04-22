#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> arr;

int n, m;
int check[8] = { 0, };

void Print()
{
	int i;
	for (i = 0; i < v.size(); i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
}

void dfs(int start,int depth)
{
	int i;
	int cnt = 0;
	if (depth == m)
	{
		Print();
		return;
	}


	for (i = 0; i < arr.size(); i++)
	{
		if (check[i] == 0) cnt++;
	}

	if (cnt < m - depth) return;

	for (i = start+1; i < arr.size(); i++)
	{
		if (check[i] == 0)
		{
			v.push_back(arr[i]);
			check[i] = 1;
			dfs(i,depth + 1);
			check[i] = 0;
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
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	for (i = 0; i < arr.size(); i++)
	{
		v.push_back(arr[i]);
		check[i] = 1;
		dfs(i,1);
		check[i] = 0;
		v.pop_back();
	}

	return 0;
}