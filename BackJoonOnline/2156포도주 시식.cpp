#include <cstdio>
#include <algorithm>
using namespace std;

int cup[10001];
int dp[4][10001];

int main()
{
	int n;
	scanf("%d", &n);
	int i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &cup[i]);
	}

	dp[0][0] = 0;
	dp[1][0] = cup[0];
	dp[2][0] = 0;

	dp[0][1] = 0;
	dp[1][1] = cup[0];
	dp[2][1] = cup[1];
	dp[3][1] = cup[0] + cup[1];

	for (i = 2; i < n; i++)
	{
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = max(dp[2][i - 1], dp[3][i - 1]);
		dp[2][i] = max(dp[0][i - 1] + cup[i], dp[1][i - 1] + cup[i]);
		dp[3][i] = dp[2][i - 1] + cup[i];
	}

	int result = -1;

	for (i = 0; i < 4; i++)
	{
		if (result < dp[i][n - 1])
		{
			result = dp[i][n - 1];
		}
	}

	printf("%d\n", result);
	return 0;
}