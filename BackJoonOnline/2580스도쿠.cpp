#include <cstdio>
#include <iostream>
using namespace std;


int map[9][9];
int statusR[9][10];
int statusC[9][10];
int square[9][10];

void dfs(int depth)
{
	int i,j,k,l;
	int checkR = 0;
	int checkC = 0;
	int x = depth / 9;
	int y = depth % 9;

	if (depth == 81)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}



	if (map[x][y] == 0)
	{
		for (k = 1; k <= 9; k++)
		{
			if ((statusR[x][k] == 0) && (statusC[y][k] == 0) && (square[((y / 3) * 3) + (x / 3)][k] == 0))
			{
				map[x][y] = k;
				statusR[x][k] = 1;
				statusC[y][k] = 1;
				square[((y / 3) * 3) + (x / 3)][k] = 1;
				dfs(depth + 1);
				map[x][y] = 0;
				statusR[x][k] = 0;
				statusC[y][k] = 0;
				square[((y / 3) * 3) + (x / 3)][k] = 0;

			}
		}
	}
	else
	{
		dfs(depth + 1);
	}
}

int main()
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &map[i][j]);
			if(map[i][j] != 0)
			{
				statusR[i][map[i][j]] = 1;
				statusC[j][map[i][j]] = 1;
				square[((j / 3) * 3) + (i / 3)][map[i][j]] = 1;
			}
		}
	}

	dfs(0);

	return 0;
}