#include <cstdio>
using namespace std;

long long dp[101][10] = { 0, };

int main()
{
	int n;

	scanf("%d", &n);

	int i, j;
	long long sum = 0;

	for (i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j] = (dp[i - 1][j + 1]) % 1000000000;
			}
			else if (j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000000;
			}
		}
	}

	for (i = 0; i <= 9; i++)
	{
		sum += dp[n][i];
	}

	sum = sum % 1000000000;

	printf("%ld", sum);

	return 0;
}