#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[51][51];
int visited[51][51] = { 0, };
int room_number[51][51] = { 0, };

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct point {
	int x;
	int y;
}point;

int n, m;
int res = -1;
int rNum = 1;

int bitmask(int num, int loc);
void bfs(int x, int y);

queue<point> q;
queue<point> roomNum;



int main()
{
	int i, j, k;
	cin >> n >> m;
	int room = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (visited[i][j] == 0)
			{
				bfs(j, i);
				room++;

			}
		}
	}

	

	int nx, ny;
	int two_size = visited[1][1];
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			for (k = 0; k < 4; k++)
			{
				ny = i + dy[k];
				nx = j + dx[k];
				
				if ((ny <= 0) || (nx <= 0) || (nx > n) || (ny > m))
				{
					continue;
				}

				if (room_number[i][j] != room_number[ny][nx])
				{
					int r_temp = visited[i][j] + visited[ny][nx];
					if (two_size < r_temp)
					{
						two_size = r_temp;
					}
				}

			}
		}
	}


	cout << room << endl;
	cout << res << endl;
	cout << two_size << endl;
	return 0;
}

void bfs(int x, int y)
{
	int i;
	int count = 1;
	point temp;
	point search;
	temp.x = x;
	temp.y = y;
	q.push(temp);
	roomNum.push(temp);
	visited[temp.y][temp.x] = 1;
	while (!q.empty())
	{
		search = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			if ((visited[search.y + dy[i]][search.x + dx[i]] == 0) && (search.y + dy[i] <= m) && (search.y + dy[i] > 0) && (search.x + dx[i] <= n) && (search.x + dx[i] > 0))
			{
				if (bitmask(map[search.y][search.x], i) == 1)
				{
					temp.x = search.x + dx[i];
					temp.y = search.y + dy[i];
					q.push(temp);
					visited[temp.y][temp.x] = 1;
					count++;
				}
			}
		}
		roomNum.push(search);
	}

	if (res < count)
	{
		res = count;
	}

	point check;
	while (!roomNum.empty())
	{
		check = roomNum.front();
		roomNum.pop();
		
		visited[check.y][check.x] = count;
		
		room_number[check.y][check.x] = rNum;
	}
	rNum++;
}

int bitmask(int num, int index)
{
	int i;
	int r;
	for (i = 0; i < index; i++)
	{
		num = num >> 1;
	}

	r = num % 2;
	if (r == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
