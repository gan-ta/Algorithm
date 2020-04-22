#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001];
int p[1001];

int main()
{
	int n;

	int i, j, k;

	scanf("%d", &n);

	for (i = 0; i < 1001; i++)
	{
		dp[i] = 10000001;
	}

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}

	dp[0] = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (dp[j] != 10000001)
			{
				for (k = 1; k < n + 1; k++)
				{
					if (j + k <= n)
					{
						dp[j + k] = min(dp[j + k], dp[j] + p[k]);
					}
				}
			}
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}