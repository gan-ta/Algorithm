#include <cstdio>
using namespace std;

int dp[201]={0,};

int main()
{
	int n, k;

	scanf("%d", &n);
	scanf("%d", &k);

	int i,j,l;

	for (i = 0; i <= n; i++)
	{
		dp[i] = 1;
	}

	for (i = 1; i < k; i++)
	{
		for (j = n; j >= 0; j--)
		{
			for (l = j-1; l >= 0; l--)
			{
				dp[j] += dp[l];
				dp[j] = dp[j] % 1000000000;
			}
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}