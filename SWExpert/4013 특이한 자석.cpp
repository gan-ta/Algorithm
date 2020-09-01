#include <deque>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<deque<int>> fac;
vector<deque<int>> temp_fac;

void clockWise(int n)
{

	int temp;
	temp = temp_fac[n].back();
	temp_fac[n].pop_back();
	temp_fac[n].push_front(temp);

}

void reverse_clockWise(int n)
{
	int temp;
	temp = temp_fac[n].front();
	temp_fac[n].pop_front();
	temp_fac[n].push_back(temp);
}

void dfs1(int n, int wise)
{
	if (n == 0)
	{
		return;
	}

	if (fac[n][6] != fac[n - 1][2])
	{
		if (wise == 1) dfs1(n - 1, -1);
		else if (wise == -1) dfs1(n - 1, 1);

		if (wise == -1) clockWise(n - 1);
		else if (wise == 1) reverse_clockWise(n - 1);
	}

	return;

}

void dfs2(int n, int wise)
{
	if (n == 3)
	{
		return;
	}

	if (fac[n][2] != fac[n + 1][6])
	{
		if (wise == 1) dfs2(n + 1, -1);
		else if (wise == -1) dfs2(n + 1, 1);

		if (wise == -1) clockWise(n + 1);
		else if (wise == 1) reverse_clockWise(n + 1);
	}

	return;
}

int main()
{
	int t, k;
	int i, j;
	int temp;
	int ans;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);

	for (int c = 0; c < t; c++)
	{
		scanf("%d", &k);
		fac.clear();
		temp_fac.clear();
		ans = 0;
		for (i = 0; i < 4; i++)
		{
			deque<int> insert;
			for (j = 0; j < 8; j++)
			{
				scanf("%d", &temp);
				insert.push_back(temp);
			}
			fac.push_back(insert);
		}

		temp_fac = fac;

		for (i = 0; i < k; i++)
		{
			int num, wise;
			scanf("%d", &num);
			scanf("%d", &wise);

			dfs1(num - 1, wise);
			dfs2(num - 1, wise);

			if (wise == 1) clockWise(num - 1);
			else if (wise == -1) reverse_clockWise(num - 1);

			fac = temp_fac;
		}


		for (i = 0; i < 4; i++)
		{
			if (fac[i][0] == 1)
			{
				ans += (int)pow(2, i);
			}
		}

		printf("#%d %d\n", c + 1, ans);

	}

	return 0;
}