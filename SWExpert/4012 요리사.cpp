#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int T;
int map[17][17];
int food_pick[17];
int n;
int div_n;
int ans;


void dfs(int food, int depth)
{
	int i, j;
	if (depth == div_n)
	{
		int sum1 = 0, sum2 = 0;
		for (i = 0; i < n; i++)
		{
			if (food_pick[i] == 1)
			{
				for (j = i + 1; j < n; j++)
				{
					if (food_pick[j] == 1) sum1 += (map[i][j] + map[j][i]);
				}
			}
			else if (food_pick[i] == 0)
			{
				for (j = i + 1; j < n; j++)
				{
					if (food_pick[j] == 0) sum2 += (map[i][j] + map[j][i]);
				}
			}
		}

		if (ans == -1) ans = abs(sum1 - sum2);
		else if (ans > abs(sum1 - sum2))  ans = abs(sum1 - sum2);
		return;
	}

	for (i = food + 1; i < n; i++)
	{
		food_pick[i] = 1;
		dfs(i, depth + 1);
		food_pick[i] = 0;
	}

}


int main()
{
	int i, j;
	int t;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		scanf("%d", &n);
		memset(food_pick, 0, sizeof(food_pick));
		div_n = n / 2;
		ans = -1;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}


		//각 음식마다 dfs를 돌면서 경우의 수 고려
		for (i = 0; i < n; i++)
		{
			food_pick[i] = 1;
			dfs(i, 1);
			food_pick[i] = 0;
		}

		printf("#%d %d\n", t + 1, ans);
	}

	return 0;
}