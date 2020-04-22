#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int check[9] = { 0, };
int n, m;

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
	int cnt= 0 ;
	if (depth == m)
	{
		Print();
		return;
	}
	
	for (i = start + 1; i <= n; i++)
	{
		if (check[i] == 0) cnt++;
	}

	if (cnt < m - depth) return;
	
	for (i = start+1; i <= n; i++)
	{
		if (check[i] == 0)
		{
			v.push_back(i);
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
	scanf("%d", &n);
	scanf("%d", &m);

	for (i = 1; i <= n; i++)
	{
		v.push_back(i);
		check[i] = 1;
		dfs(i,1);
		check[i] = 0;
		v.pop_back();
	}

	return 0;
}