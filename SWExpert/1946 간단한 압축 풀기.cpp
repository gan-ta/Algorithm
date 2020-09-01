#include <stdio.h>
char arr[201];
int idx = 1;
int sum = 0;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int i, j, k;
	for (i = 0; i < T; i++)
	{
		int N;
		scanf("%d", &N);
		int cut1, cut2;
		for (j = 0; j < N; j++)
		{
			getchar();
			char c;
			scanf("%c", &c);
			int num;
			scanf("%d", &num);
			sum += num;
			for (k = idx; k < (idx + num); k++)
			{
				arr[k] = c;
			}
			idx = k;
		}

		cut1 = sum / 10;
		cut2 = sum % 10;

		printf("#%d\n", i + 1);
		for (j = 0; j < cut1; j++)
		{
			for (k = 1; k <= 10; k++)
			{
				printf("%c", arr[10 * j + k]);
			}
			printf("\n");
		}
		for (k = 1; k <= cut2; k++)
		{
			printf("%c", arr[10 * cut1 + k]);
		}
		printf("\n");

		for (j = 0; j < 201; j++)
		{
			arr[j] = NULL;
		}
		idx = 1;
		sum = 0;
	}
	return 0;
}