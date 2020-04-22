#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

typedef struct room {
	int r;
	int c;
}room;



int map[10][10];
int temp_map[10][10];
int n, m;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void map_copy()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			temp_map[i][j] = map[i][j];
		}
	}

}


int bfs()
{
	int i,j;
	int nr, nc;
	int res= 0;
	queue<room> q;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (temp_map[i][j] == 2)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		room search = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			nr = search.r + dr[i];
			nc = search.c + dc[i];

			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (temp_map[nr][nc] == 0)
				{
					q.push({ nr,nc });
					temp_map[nr][nc] = 2;
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (temp_map[i][j] == 0)
			{
				res++;
			}
		}
	}

	return res;
}

int main()
{
	vector<room> room_list;
	vector<int> idx;
	int i, j,k;
	int temp_ans;
	int ans = -1;
	scanf("%d %d", &n,&m);


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m ;j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
			{
				room_list.push_back({ i,j });
			}
		}
	}

	for (i = 0; i < room_list.size()-2; i++)
	{
		for (j = i + 1; j < room_list.size() - 1; j++)
		{
			for (k = j + 1; k < room_list.size(); k++)
			{
				room room1,room2,room3;
				room1 = room_list[i];
				room2 = room_list[j];
				room3 = room_list[k];

				map_copy();

				temp_map[room1.r][room1.c] = 1;
				temp_map[room2.r][room2.c] = 1;
				temp_map[room3.r][room3.c] = 1;
				temp_ans = bfs();
				if (ans < temp_ans)
				{
					ans = temp_ans;
				}

			}
		}
	}

	printf("%d\n", ans);

	return 0;
}