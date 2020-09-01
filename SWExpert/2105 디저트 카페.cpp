#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int dessert[101];
int map[21][21];

int dr[4] = { -1,-1,1,1 };
int dc[4] = { -1,1,1,-1 };

int sr = 0;
int sc = 0;
int ans = -1;
int n;

bool check_direct(int num, int check)
{
	int i;
	for (i = 0; i < num; i++)
	{
		check = check >> 1;
	}

	if ((check % 2 == 0)) return true;
	else return false;
}

void dfs(int r, int c, int direct, int cnt, int check)
{
	int nr, nc;
	int new_direct;
	int new_check;

	if ((r == sr) && (c == sc))
	{
		if (ans < cnt) ans = cnt;
		return;
	}

	new_direct = (direct + 1) % 4;
	if (check_direct(new_direct, check))
	{
		new_check = check + pow(2, new_direct);

		nr = r + dr[new_direct];
		nc = c + dc[new_direct];

		if (nr >= 0 && nr < n && nc >= 0 && nc < n)
		{
			if ((dessert[map[nr][nc]] == 0) || ((nr == sr) && (nc == sc)))
			{
				dessert[map[nr][nc]] = 1;
				dfs(nr, nc, new_direct, cnt + 1, new_check);
				if (!((nr == sr) && (nc == sc)))
				{
					dessert[map[nr][nc]] = 0;
				}
			}
		}
	}


	//진행방향 그대로
	nr = r + dr[direct];
	nc = c + dc[direct];

	if (nr >= 0 && nr < n && nc >= 0 && nc < n)
	{
		if ((dessert[map[nr][nc]] == 0) || ((nr == sr) && (nc == sc)))
		{
			dessert[map[nr][nc]] = 1;
			dfs(nr, nc, direct, cnt + 1, check);
			if (!((nr == sr) && (nc == sc)))
			{
				dessert[map[nr][nc]] = 0;
			}
		}
	}


	new_direct = (direct - 1) % 4;
	if (check_direct(new_direct, check))
	{
		new_check = check + pow(2, new_direct);

		nr = r + dr[new_direct];
		nc = c + dc[new_direct];

		if (nr >= 0 && nr < n && nc >= 0 && nc < n)
		{
			if ((dessert[map[nr][nc]] == 0) || ((nr == sr) && (nc == sc)))
			{
				dessert[map[nr][nc]] = 1;
				dfs(nr, nc, new_direct, cnt + 1, new_check);
				if (!((nr == sr) && (nc == sc)))
				{
					dessert[map[nr][nc]] = 0;
				}
			}
		}
	}


}

int main()
{
	int T;
	int t, i, j;
	int temp;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		ans = -1;
		memset(map, 0, sizeof(map));
		memset(dessert, 0, sizeof(dessert));
		scanf("%d", &n);
		//맵에 할당
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%d", &temp);
				map[i][j] = temp;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				sr = i;
				sc = j;

				//r,c,direct, cnt,check;
				dessert[map[i][j]] = 1;

				if ((i - 1 >= 0) && (j - 1 >= 0))
				{
					if ((dessert[map[i - 1][j - 1]] == 0))
					{
						dessert[map[i - 1][j - 1]] = 1;
						dfs(i - 1, j - 1, 0, 1, 1);
						dessert[map[i - 1][j - 1]] = 0;
					}
				}

				if ((i - 1 >= 0) && (j + 1 < n))
				{
					if ((dessert[map[i - 1][j + 1]] == 0))
					{
						dessert[map[i - 1][j + 1]] = 1;
						dfs(i - 1, j + 1, 1, 1, 2);
						dessert[map[i - 1][j + 1]] = 0;
					}
				}

				if ((i + 1 < n) && (j + 1 < n))
				{
					if ((dessert[map[i + 1][j + 1]] == 0))
					{
						dessert[map[i + 1][j + 1]] = 1;
						dfs(i + 1, j + 1, 2, 1, 4);
						dessert[map[i + 1][j + 1]] = 0;
					}
				}

				if ((i + 1 < n) && (j - 1 >= 0))
				{
					if ((dessert[map[i + 1][j - 1]] == 0))
					{
						dessert[map[i + 1][j - 1]] = 1;
						dfs(i + 1, j - 1, 3, 1, 8);
						dessert[map[i + 1][j - 1]] = 0;
					}
				}

				dessert[map[i][j]] = 0;

			}
		}

		printf("#%d %d\n", t + 1, ans);

	}

	return 0;
}