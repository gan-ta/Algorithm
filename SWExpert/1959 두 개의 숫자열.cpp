#include <stdio.h>
int a[21];
int b[21];
int temp = 0;
int sum = 0;
int result;
int count = 0;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int i, j, k;
	for (i = 1; i <= T; i++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		/*�迭�� ������ ����*/
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a[j]);
		}
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &b[j]);
		}

		/*����� �� ������ �Ǻ�*/
		if (N >= M) //a�� �� ��ٸ�
		{
			for (j = 1; j <= (N - M + 1); j++)
			{
				for (k = 1; k <= M; k++)
				{
					sum += b[k] * a[j + k - 1];
					//sum += temp;
				}
				if (count == 0) // ó�� ����̸� �׳� ������ �ʱ�ȭ 
				{
					count++;
					result = sum;
					sum = 0;
				}
				else if (count == 1) // ���� ����̸� �ִ밫�� ������ �� ��
				{
					if (result < sum)
					{
						result = sum;
						sum = 0;
					}
					else
					{
						sum = 0;
					}
				}
			}
		}
		else//b�� �� ��ٸ�
		{
			for (j = 1; j <= (M - N + 1); j++)
			{
				for (k = 1; k <= N; k++)
				{
					sum += a[k] * b[j + k - 1];
					//sum += temp;
				}
				if (count == 0) // ó�� ����̸� �׳� ������ �ʱ�ȭ 
				{
					count++;
					result = sum;
					sum = 0;
				}
				else if (count == 1) // ���� ����̸� �ִ밫�� ������ �� ��
				{
					if (result < sum)
					{
						result = sum;
						sum = 0;
					}
					else
					{
						sum = 0;
					}
				}
			}
		}
		printf("#%d %d\n", i, result);
		sum = 0;
		result = 0;
		temp = 0;
		count = 0;
		for (j = 0; j <= 20; j++)
		{
			a[j] = 0;
			b[j] = 0;
		}
	}
	return 0;
}