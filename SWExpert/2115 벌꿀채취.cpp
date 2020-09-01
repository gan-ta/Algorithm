#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n, m, c;
int map[11][11];
int ans = -1;
vector<int> pick1;
vector<int> pick2;

vector<int> des_area(int r, int c)
{
	vector<int> res;
	if (c + m > n) return res;
	else
	{
		for (int i = c; i < c + m; i++)
		{
			res.push_back(map[r][i]);
		}
	}
	return res;

}


void calculate()
{
	int res1 = -1;
	int res2 = -1;
	int temp_res1 = 0;
	int temp_res2 = 0;
	int dou_temp_res1 = 0;
	int dou_temp_res2 = 0;
	int temp;

	//모든 조합의 경우에 대하여 고려하여 최댓값을 뽑음
	for (int i = 0; i < pow(2, m); i++)
	{
		temp_res1 = 0;
		temp_res2 = 0;
		dou_temp_res1 = 0;
		dou_temp_res2 = 0;
		for (int j = 0; j < m; j++)
		{
			temp = pow(2, j);
			if ((i & temp) == temp)
			{
				temp_res1 += pick1[j];
				dou_temp_res1 += pow(pick1[j], 2);
				temp_res2 += pick2[j];
				dou_temp_res2 += pow(pick2[j], 2);
			}
		}

		if (res1 < dou_temp_res1 && temp_res1 <= c)
		{
			res1 = dou_temp_res1;
		}

		if (res2 < dou_temp_res2 && temp_res2 <= c)
		{
			res2 = dou_temp_res2;
		}
	}

	if ((ans == -1) || ans < (res1 + res2))
	{
		ans = res1 + res2;
	}

}


int main()
{
	int T;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		scanf("%d %d %d", &n, &m, &c);
		memset(map, 0, sizeof(map));
		ans = -1;

		//꿀벌통 상태저장
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				pick1 = des_area(i, j);
				if (pick1.size() == 0) continue;
				for (int k = i; k < n; k++)
				{
					if (k == i)
					{
						for (int l = j + m; l < n; l++)
						{
							pick2 = des_area(k, l);
							if (pick2.size() == 0) continue;
							calculate();
						}
					}
					else
					{
						for (int l = 0; l < n; l++)
						{
							pick2 = des_area(k, l);

							if ((pick1.size() != 0) && (pick2.size() != 0))
							{
								calculate();
							}

						}
					}
				}

			}
		}

		printf("#%d %d\n", t + 1, ans);

	}
	return 0;
}