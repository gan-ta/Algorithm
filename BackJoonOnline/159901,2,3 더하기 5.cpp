#include <cstdio>
using namespace std;


long long dp[100001][4] = { 0, };

int main()
{
	int t;
	int i, j;

	scanf("%d", &t);

	dp[1][1] = 1;

	dp[2][2] = 1;

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;


	for (i = 4; i <= 100000; i++)
	{
		dp[i][1] = dp[i - 1][2] + dp[i - 1][3] % 1000000009;
		dp[i][2] = dp[i - 2][1] + dp[i - 2][3] % 1000000009;
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] % 1000000009;
	}

	for (i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		long long sum = 0;
		for (j = 1; j < 4; j++)
		{
			sum += dp[n][j];
		}

		printf("%d\n", sum % 1000000009);

	}

	return 0;
}
