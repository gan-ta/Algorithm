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

//Ȯ�ο� �Լ�
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

//���� ����
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

//���� ����
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

//��������
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


//������ �� ���� ������ �ٽ� �׷���
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

//��� ������ ���ִ� �Լ�
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

	//�ش� �Լ��� ���� ���� �� ����
	int storage_map[15][12] = { 0, };
	int storage_map2[15][12] = { 0, };
	int top[12] = { 0, };
	deep_copy_storage(storage_map);
	deep_copy_storage(storage_map2);
	//printf("depth: %d\n", depth);
	//print_map(storage_map);

	//����� ���� ����ϴ� ����
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

		//printf("%d���� ���� ����\n", i);

		deep_copy_storage_storage(storage_map, storage_map2);
		info insert = info({ top[i],i,storage_map[top[i]][i] });
		q.push(insert);

		//���� �μ��� ����
		while (!q.empty())
		{
			info search = q.front();
			q.pop();

			//�ش� �ڽ� ����
			storage_map[search.r][search.c] = 0;

			//�ֺ� �ڽ� ť���ٰ� �־��ֱ�

			//������
			for (j = 1; j < search.num; j++)
			{
				if (search.r - j < 0) break;
				if (storage_map[search.r - j][search.c] != 0)
				{
					q.push(info({ search.r - j,search.c,storage_map[search.r - j][search.c] }));
				}
			}

			//�Ʒ�����
			for (j = 1; j < search.num; j++)
			{
				if (search.r + j >= h) break;
				if (storage_map[search.r + j][search.c] != 0)
				{
					q.push(info({ search.r + j,search.c,storage_map[search.r + j][search.c] }));
				}
			}

			//����
			for (j = 1; j < search.num; j++)
			{
				if (search.c - j < 0) break;
				if (storage_map[search.r][search.c - j] != 0)
				{
					q.push(info({ search.r,search.c - j,storage_map[search.r][search.c - j] }));
				}
			}

			//����
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