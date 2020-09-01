#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

int map[21][21];
vector<pair<int, int>> homelist;


int n, m;

//k와 시작점의 위치를 받아 서비스 받는 집의 갯수 반환
int calc_home(int k, int r, int c)
{
	int res = 0;
	for (int i = 0; i < homelist.size(); i++)
	{
		int dist = 0;
		dist = abs(r - homelist[i].first) + abs(c - homelist[i].second);

		if (dist <= (k - 1))
		{
			res++;
		}
	}
	return res;

}

int main()
{
	int T;
	int max_k = 1;
	int ans = 0;
	int temp_ans;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		homelist.clear();
		memset(map, 0, sizeof(map));
		scanf("%d %d", &n, &m);
		ans = 0;
		max_k = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) {
					homelist.push_back(pair <int, int>(i, j)); //집의 위치 정보를 넣어줌

				}
			}
		}

		//k를 몇까지 늘릴 것인지 계산
		while (1)
		{
			if ((max_k * max_k) + ((max_k - 1) * (max_k - 1)) > (int)homelist.size() * m) break;

			max_k++;
		}


		//맵을 순환하면서 해당k를 넣어주고 순익을 계산
		for (int k = 1; k < max_k; k++)
		{
			int cost = (k * k) + ((k - 1) * (k - 1));
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{

					temp_ans = calc_home(k, i, j);
					if (cost <= temp_ans * m)
					{
						if (ans < temp_ans) ans = temp_ans;
					}
				}
			}
		}

		printf("#%d %d\n", t + 1, ans);


	}
	return 0;
}