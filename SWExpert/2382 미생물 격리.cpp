#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

//상,좌,하,우
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };


typedef struct info {
	int r;
	int c;
	int count;
	int dir;
}info;


int T, n, m, k;

deque<info> status;
deque<info> temp_status;

vector<info> map[101][101];

bool sort_count(info a, info b)
{
	return a.count > b.count;
}

void map_reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j].clear();
		}
	}
}

void chcek_collision()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j].size() == 1)
			{
				temp_status.push_front(map[i][j][0]);

			}
			else if (map[i][j].size() > 1)
			{
				sort(map[i][j].begin(), map[i][j].end(), sort_count);
				info insert;
				insert.r = map[i][j][0].r;
				insert.c = map[i][j][0].c;
				insert.dir = map[i][j][0].dir;
				insert.count = 0;
				for (int k = 0; k < map[i][j].size(); k++)
				{
					insert.count += map[i][j][k].count;
				}
				temp_status.push_front(insert);
			}
		}
	}
}


void simulation()
{

	int q_size = status.size();
	temp_status.clear();
	map_reset();

	for (int i = 0; i < q_size; i++)
	{
		//큐의 크기만큼 시물레이션 돌림
		info search;
		search = status.back();
		status.pop_back();

		//이동을 시켜줌
		search.r += dr[search.dir];
		search.c += dc[search.dir];

		if (search.r == 0 || search.r == n - 1 || search.c == 0 || search.c == n - 1)
		{
			search.count = search.count / 2;
			search.dir = (search.dir + 2) % 4;
		}

		map[search.r][search.c].push_back(search);
	}

	chcek_collision();

	status = temp_status;

}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int ans = 0;
		scanf("%d %d %d", &n, &m, &k);//정사각형 넓이, 격리시간, 군집갯수
		map_reset();
		status.clear();
		temp_status.clear();
		for (int i = 0; i < k; i++)
		{
			int temp_r, temp_c, temp_count, temp_dir;
			int temp_dir2;
			scanf("%d %d %d %d", &temp_r, &temp_c, &temp_count, &temp_dir);
			temp_dir--;
			if (temp_dir == 1) temp_dir2 = 2;
			else if (temp_dir == 2) temp_dir2 = 1;
			else temp_dir2 = temp_dir;

			status.push_front({ temp_r,temp_c,temp_count,temp_dir2 });
		}

		for (int i = 0; i < m; i++)
		{
			simulation();
		}

		for (int i = 0; i < status.size(); i++)
		{
			ans += status[i].count;
		}
		printf("#%d %d\n", t + 1, ans);
	}
	return 0;
}