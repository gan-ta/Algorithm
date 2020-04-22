#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001];
int p[1001];

int main()
{
	int n;

	scanf("%d", &n);

	memset(dp, -1, sizeof(dp));

	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
	}

	dp[n] = 0;

	for (i = 0; i < n; i++)
	{
		for (j = n; j >= 0; j--)
		{
			if (dp[j] != -1)
			{
				for (k = 1; k < n + 1; k++)
				{
					if (j - k >= 0)
					{
						dp[j - k] = max(dp[j - k], dp[j] + p[k]);
					}
				}
			}
		}
	}

	printf("%d\n", dp[0]);

	return 0;
}