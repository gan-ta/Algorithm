#include <cstdio>
#include <vector>
using namespace std;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

int r, c, t;
int up_r = -1, up_c = -1, down_r, down_c;
int res = 0;
vector<vector<int>> map;
vector<vector<int>> temp_map;


void simulation(int depth)
{
	int i, j,k;
	int amount;
	int cnt = 0;
	int nr, nc;
	int point_r;
	int point_c;
	int new_r,new_c;
	if (depth == t)
	{
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (map[i][j] != -1)
				{
					res += map[i][j];
				}
			}
		}
		return;
	}

	temp_map = map;

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			cnt = 0;
			if (map[i][j] != 0)
			{
				amount = map[i][j]/5;
				for (k = 0; k < 4; k++)
				{
					nr = i + dr[k];
					nc = j + dc[k];
					if (nr >= 0 && nr < r && nc >= 0 && nc < c)
					{
						if (map[nr][nc] != -1)
						{
							temp_map[nr][nc] += amount;
							cnt++;
						}
					}
				}
				temp_map[i][j] -= (cnt * amount);
			}
		}
	}

	point_r = up_r;
	point_c = up_c+1;
	int move_r[4] = {0,-1,0,1};
	int move_c[4] = {1,0,-1,0};
	int dir = 0;
	amount = temp_map[point_r][point_c];
	temp_map[point_r][point_c] = 0;
	int temp_amount;
	while (1)
	{
		new_r = point_r + move_r[dir];
		new_c = point_c + move_c[dir];

		if ((new_r == up_r) && (new_c == up_c)) break;

		if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c)
		{
			temp_amount = temp_map[new_r][new_c];
			temp_map[new_r][new_c] = amount;
			amount = temp_amount;
			point_r = new_r;
			point_c = new_c;
			continue;
		}
		else
		{
			dir += 1;
			continue;
		}
	}


	point_r = down_r;
	point_c = down_c + 1;
	move_r[1] = 1;
	move_r[3] = -1;
	dir = 0;
	amount = temp_map[point_r][point_c];
	temp_map[point_r][point_c] = 0;
	while (1)
	{
		new_r = point_r + move_r[dir];
		new_c = point_c + move_c[dir];

		if ((new_r == down_r) && (new_c == down_c)) break;

		if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c)
		{
			temp_amount = temp_map[new_r][new_c];
			temp_map[new_r][new_c] = amount;
			amount = temp_amount;
			point_r = new_r;
			point_c = new_c;
			continue;
		}
		else
		{
			dir += 1;
			continue;
		}
	}

	map = temp_map;

	simulation(depth + 1);
}

int main()
{
	int i, j;
	vector<int> insert;
	int num;
	scanf("%d %d %d", &r, &c, &t);
	for (i = 0; i < r; i++)
	{
		insert.clear();
		for (j = 0; j < c; j++)
		{
			scanf("%d", &num);
			insert.push_back(num);
			if (num == -1)
			{
				if (up_r == -1)
				{
					up_r = i;
					up_c = j;
				}
				else
				{
					down_r = i;
					down_c = j;
				}
			}
		}
		map.push_back(insert);
	}


	simulation(0);

	printf("%d\n", res);

	return 0;
}