#include <iostream>
#include <queue>
using namespace std;

int m, n, h, cnt;
int box[100][100][100];

int dh[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };

typedef struct point {
	int x, y, z;
};

queue<point> q;
int ans = 0;

void bfs()
{
	int size;
	point pop_p;
	point push_p;
	point temp;

	int x, y, z;
	int nx, ny, nz;
	int i, j;
	while (!q.empty())
	{
		size = q.size();
		ans++;
		for (i = 0; i < size; i++)
		{
			pop_p = q.front();
			q.pop();

			x = pop_p.x;
			y = pop_p.y;
			z = pop_p.z;
			for (j = 0; j < 6; j++)
			{
				nx = x + dh[j];
				ny = y + dr[j];
				nz = z + dc[j];

				if (nx >= 0 && nx < h && ny >= 0 && ny < n && nz >= 0 && nz < m)
				{
					if (box[nx][ny][nz] == 0)
					{
						temp.x = nx;
						temp.y = ny;
						temp.z = nz;
						q.push(temp);
						box[nx][ny][nz] = 1;
					}
				}


			}
		}
	}

}

int main()
{
	cin >> m >> n >> h;
	point temp;
	int i, j, k;
	for (i = 0; i < h; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			for (k = 0; k < m; ++k)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					temp.x = i;
					temp.y = j;
					temp.z = k;
					q.push(temp);
				}
			}
		}
	}

	bfs();

	int check = 0;

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				break;
			}
		}
		if (check == 1)
		{
			break;
		}
	}
	if (check == 1)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans - 1 << endl;
	}


	return 0;
}