#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int map[15][12];
int temp_map[15][12];
int n, w, h;
int ans = 200;

typedef struct info {
	int r;
	int c;
	int num;
}info;

queue<info> q;
stack<int> s;

//확인용 함수
void print_map(int temp_map[15][12])
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			printf("%d ", temp_map[i][j]);
		}
		printf("\n");
	}
}

//깊은 복사
void deep_copy_storage(int storage_map[15][12])
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			storage_map[i][j] = temp_map[i][j];
		}
	}
}

//깊은 복사
void deep_copy_temp(int storage_map[15][12])
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			temp_map[i][j] = storage_map[i][j];
		}
	}
}

//깊은복사
void deep_copy_storage_storage(int storage_map1[15][12], int storage_map2[15][12])
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			storage_map1[i][j] = storage_map2[i][j];
		}
	}
}


//벽돌을 꺤 후의 지도를 다시 그려줌
void rearrange_map(int storage_map[15][12])
{
	int i, j;
	int temp = 0;

	for (i = 0; i < w; i++)
	{
		temp = 0;
		for (j = 0; j < h; j++)
		{
			if (storage_map[j][i] != 0)
			{
				s.push(storage_map[j][i]);
				storage_map[j][i] = 0;
			}
		}

		while (!s.empty())
		{
			storage_map[(h - 1) - temp][i] = s.top();
			temp++;
			s.pop();
		}
	}
}

//블록 갯수를 세주는 함수
int calc_block(int temp_map[15][12])
{
	int i, j;
	int res = 0;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (temp_map[i][j] != 0) res++;
		}
	}

	return res;
}

void dfs(int depth)
{
	if (depth == n)
	{
		//printf("depth: %d\n", depth);
		//print_map(temp_map);
		int res = calc_block(temp_map);
		if (ans > res)
		{
			ans = res;
			//printf("%d\n", res);
		}
		return;
	}

	int i, j;

	//해당 함수의 현재 상태 맵 저장
	int storage_map[15][12] = { 0, };
	int storage_map2[15][12] = { 0, };
	int top[12] = { 0, };
	deep_copy_storage(storage_map);
	deep_copy_storage(storage_map2);
	//printf("depth: %d\n", depth);
	//print_map(storage_map);

	//꼭대기 층을 계산하는 과정
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < h; j++)
		{
			if (temp_map[j][i] != 0)
			{
				top[i] = j;
				break;
			}
		}
	}

	for (i = 0; i < w; i++)
	{
		int temp_top = top[i];

		//printf("%d번재 열을 없앰\n", i);

		deep_copy_storage_storage(storage_map, storage_map2);
		info insert = info({ top[i],i,storage_map[top[i]][i] });
		q.push(insert);

		//벽을 부수는 과정
		while (!q.empty())
		{
			info search = q.front();
			q.pop();

			//해당 박스 깨기
			storage_map[search.r][search.c] = 0;

			//주변 박스 큐에다가 넣어주기

			//윗방향
			for (j = 1; j < search.num; j++)
			{
				if (search.r - j < 0) break;
				if (storage_map[search.r - j][search.c] != 0)
				{
					q.push(info({ search.r - j,search.c,storage_map[search.r - j][search.c] }));
				}
			}

			//아래방향
			for (j = 1; j < search.num; j++)
			{
				if (search.r + j >= h) break;
				if (storage_map[search.r + j][search.c] != 0)
				{
					q.push(info({ search.r + j,search.c,storage_map[search.r + j][search.c] }));
				}
			}

			//좌측
			for (j = 1; j < search.num; j++)
			{
				if (search.c - j < 0) break;
				if (storage_map[search.r][search.c - j] != 0)
				{
					q.push(info({ search.r,search.c - j,storage_map[search.r][search.c - j] }));
				}
			}

			//우측
			for (j = 1; j < search.num; j++)
			{
				if (search.c + j >= w) break;
				if (storage_map[search.r][search.c + j] != 0)
				{
					q.push(info({ search.r,search.c + j,storage_map[search.r][search.c + j] }));
				}
			}
		}
		rearrange_map(storage_map);
		deep_copy_temp(storage_map);
		dfs(depth + 1);
	}

}


int main()
{

	int t;
	int i, j;
	int temp;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int c = 0; c < t; c++)
	{
		scanf("%d", &n);
		scanf("%d", &w);
		scanf("%d", &h);
		ans = 200;
		memset(map, 0, sizeof(map));
		memset(temp_map, 0, sizeof(temp_map));

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				scanf("%d", &temp);
				map[i][j] = temp;
			}
		}

		for (i = 0; i < h; i++)
		{
			for (j = 0; j < w; j++)
			{
				temp_map[i][j] = map[i][j];
			}
		}


		dfs(0);

		printf("#%d %d\n", c + 1, ans);
	}

	return 0;
}