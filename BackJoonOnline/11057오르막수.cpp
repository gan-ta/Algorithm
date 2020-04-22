#include <cstdio>
using namespace std;

int dp[1001][11] = { 0, };

void fun(int d, int k)
{
	int i;
	for (i = 0; i <= k; i++)
	{
		dp[d][k] += dp[d - 1][i];
		dp[d][k] = dp[d][k] % 10007;
	}
}

int main()
{

	int i, j;
	int sum = 0;

	for (i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	int n;

	scanf("%d", &n);

	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			fun(i, j);
		}
	}

	for (i = 0; i <= 9; i++)
	{
		sum += dp[n][i];
	}

	printf("%d\n", sum % 10007);


	return 0;
}