#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10001];

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	int i, j;
	int max = 0;
	int index = 0;
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	i = n - 1;

	while (i > 0 && a[i - 1] < a[i]) i--;

	if (i == 0)
	{
		printf("-1\n");
	}
	else
	{
		for (j = i; j < n; j++)
		{
			if (a[i - 1] > a[j] && a[j] > max)
			{
				max = a[j];
				index = j;
			}
		}

		temp = a[i - 1];
		a[i - 1] = a[index];
		a[index] = temp;

		sort(a + i, a + n, desc);

		for (j = 0; j < n; j++)
		{
			printf("%d ", a[j]);
		}
	}

	return 0;
}