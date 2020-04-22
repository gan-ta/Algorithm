#include <cstdio>
#include <algorithm>
using namespace std;

int a[10000];

int main()
{
	int n;
	int i;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	if (next_permutation(a, a + n))
	{
		for (i = 0; i < n; i++)
		{
			printf("%d ", a[i]);
		}
	}
	else
	{
		printf("-1\n");
	}

	return 0;
}