#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


typedef struct home {
	int r;
	int c;
}home;

typedef struct store{
	int r;
	int c;
}store;


int main()
{
	int i, j,k;
	int n, m;
	int store_cnt = 0;
	int ans =  -1;

	vector<home> home_list;
	vector<store> store_list;
	vector<int> idx;

	scanf("%d %d", &n, &m);

	int temp;
	int group;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &temp);

			if (temp == 1)
			{
				home_list.push_back({ i,j});
			}
			else if (temp == 2)
			{
				store_list.push_back({ i,j});
				store_cnt++;
			}
		}
	}

	group = pow(2, store_cnt);

	for (i = 1; i < group; i++)
	{
		int group_stat = i;
		int check = 0;
		int second_ans = 0;
		idx.clear();
		for (j = 0; j < store_cnt; j++)
		{
			if ((group_stat & 1) == 1)
			{
				check++;
				idx.push_back(j);
			}
			group_stat = group_stat >> 1;
		}

		if (check != m) continue;


		for (j = 0; j < home_list.size(); j++)
		{
			int min = 1001;
			int dist;
			for (k = 0; k < idx.size(); k++)
			{
				dist = abs(home_list[j].r - store_list[idx[k]].r) + abs(home_list[j].c - store_list[idx[k]].c);
				if (min > dist)
				{
					min = dist;
				}
			}
			second_ans += min;
		}

		if (ans == -1)
		{
			ans = second_ans;
		}
		else
		{
			if (ans > second_ans)
			{
				ans = second_ans;
			}
		}
	}


	printf("%d\n", ans);
	return 0;
}