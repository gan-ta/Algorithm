#include <stdio.h>
#include <string.h>

int a[21][21];

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int i, j, k, l;
	for (i = 0; i < T; i++)
	{
		int N;
		char str[7];
		int temp2[21][21] = { 0, };
		int count = 1;
		int count2 = 1;
		int idx = 0;
		scanf("%d", &N);
		getchar();
		scanf("%s", str);
		getchar();
		for (j = 1; j <= N; j++)
		{
			for (k = 1; k <= N; k++)
			{
				scanf("%d", &a[j][k]);
			}
		}
		printf("#%d\n", i + 1);
		if (strcmp(str, "left") == 0) //왼쪽으로 밀면
		{
			count = 1;
			for (j = 1; j <= N; j++) //행을 기준으로
			{
				for (k = 1; k <= N; k++)
				{
					if (a[j][k] != 0)
					{
						if (idx == 0)
						{
							idx = k;
						}
						else
						{
							if (a[j][k] == a[j][idx])
							{
								temp2[j][count++] = a[j][k] + a[j][idx];
								idx = 0;
							}
							else
							{
								temp2[j][count++] = a[j][idx];
								idx = k;
							}
						}
					}
				}
				if (idx != 0)
				{
					temp2[j][count] = a[j][idx];
				}
				idx = 0;
				count = 1;
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					printf("%d ", temp2[j][k]);
				}
				printf("\n");
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					temp2[j][k] = 0;
				}
			}
		}

		if (strcmp(str, "right") == 0) //오른쪽으로 밀면
		{
			count = N;
			for (j = 1; j <= N; j++) //행을 기준으로
			{
				for (k = N; k >= 1; k--)
				{
					if (a[j][k] != 0)
					{
						if (idx == 0)
						{
							idx = k;
						}
						else
						{
							if (a[j][k] == a[j][idx])
							{
								temp2[j][count--] = a[j][k] + a[j][idx];
								idx = 0;
							}
							else
							{
								temp2[j][count--] = a[j][idx];
								idx = k;
							}
						}
					}
				}
				if (idx != 0)
				{
					temp2[j][count] = a[j][idx];
				}
				idx = 0;
				count = N;

			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					printf("%d ", temp2[j][k]);
				}
				printf("\n");
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					temp2[j][k] = 0;
				}
			}
		}

		if (strcmp(str, "up") == 0) //위쪽으로 밀면
		{
			count = 1;
			for (j = 1; j <= N; j++) //열을 기준으로
			{
				for (k = 1; k <= N; k++)
				{
					if (a[k][j] != 0)
					{
						if (idx == 0)
						{
							idx = k;
						}
						else
						{
							if (a[k][j] == a[idx][j])
							{
								temp2[count++][j] = a[k][j] + a[idx][j];
								idx = 0;
							}
							else
							{
								temp2[count++][j] = a[idx][j];
								idx = k;
							}
						}
					}

				}
				if (idx != 0)
				{
					temp2[count][j] = a[idx][j];
				}
				idx = 0;
				count = 1;
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					printf("%d ", temp2[j][k]);
				}
				printf("\n");
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					temp2[j][k] = 0;
				}
			}
		}

		if (strcmp(str, "down") == 0) //위쪽으로 밀면
		{
			count = N;
			for (j = 1; j <= N; j++) //열을 기준으로
			{
				for (k = N; k >= 1; k--)
				{
					if (a[k][j] != 0)
					{
						if (idx == 0)
						{
							idx = k;
						}
						else
						{
							if (a[k][j] == a[idx][j])
							{
								temp2[count--][j] = a[k][j] + a[idx][j];
								idx = 0;
							}
							else
							{
								temp2[count--][j] = a[idx][j];
								idx = k;
							}
						}
					}
				}
				if (idx != 0)
				{
					temp2[count][j] = a[idx][j];
				}
				idx = 0;
				count = N;
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					printf("%d ", temp2[j][k]);
				}
				printf("\n");
			}
			for (j = 1; j <= N; j++)
			{
				for (k = 1; k <= N; k++)
				{
					temp2[j][k] = 0;
				}
			}
		}

	}
	return 0;
}