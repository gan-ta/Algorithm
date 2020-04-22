#include <cstdio>
using namespace std;

long long dp[91][2];

int main()
{
	int n;
	long long sum;

	scanf("%d", &n);

	int i, j;

	dp[1][0] = 0;
	dp[1][1] = 1;

	for (i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	sum = dp[n][0] + dp[n][1];

	printf("%ld\n", sum);
	return 0;
}