#include <stdio.h>

int a[101][101];
int max = 0;
int sum = 0;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int i, j, k;
	for (i = 0; i < 10; i++)
	{
		int N;
		scanf("%d", &N);
		for (j = 1; j <= 100; j++)
		{
			for (k = 1; k <= 100; k++)
			{
				scanf("%d", &a[j][k]);
			}
		}

		/*행을 기준으로의 합*/
		for (j = 1; j <= 100; j++)
		{
			for (k = 1; k <= 100; k++)
			{
				sum += a[j][k];
			}
			if (max < sum)
			{
				max = sum;
			}
			sum = 0;
		}

		/*열을 기준으로의 합*/
		for (k = 1; k <= 100; k++)
		{
			for (j = 1; j <= 100; j++)
			{
				sum += a[j][k];
			}
			if (max < sum)
			{
				max = sum;
			}
			sum = 0;
		}

		/*정방향 대각선 기준으로의 합*/
		for (j = 1; j <= 100; j++)
		{
			sum += a[j][j];
			if (max < sum)
			{
				max = sum;
			}
			sum = 0;
		}

		/*역방향 대각선 기준으로의 합*/
		for (j = 1; j <= 100; j++)
		{
			sum += a[j][100 - (j - 1)];
			if (max < sum)
			{
				max = sum;
			}
			sum = 0;
		}

		printf("#%d %d\n", N, max);
		max = 0;
	}

	return 0;
}