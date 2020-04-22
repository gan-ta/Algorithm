#include <cstdio>
#include <algorithm>
using namespace std;

int a[8];

int main()
{
	int n;
	int i;
	int j;
	int min = 10001;
	int index = 0;
	int temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}

	while (1)
	{
		min = 10001;
		
		for (i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}

		printf("\n");

		i = n - 1;
		while (i > 0 && a[i - 1] > a[i]) i--;
		if (i == 0) break;
		else
		{
			for (j = i; j < n; j++)
			{
				if (a[i - 1] < a[j] && min > a[j])
				{
					min = a[j];
					index = j;
				}
			}
			temp = a[i - 1];
			a[i - 1] = a[index];
			a[index] = temp;

			sort(a + i, a + n);
		}

	}
	return 0;
}