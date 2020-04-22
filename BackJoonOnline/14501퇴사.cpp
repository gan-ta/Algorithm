#include <cstdio>
#include <algorithm>
using namespace std;

int t[16];
int p[16];
int dp[16][6] = {0,};

int main()
{
	int i,j;
	int a, b;
	int n;
	int res = -1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		t[i] = a;
		p[i] = b;
	}

	dp[1][0] = 0;
	dp[1][t[1]] = p[1];

	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= 5; j++)
		{
			dp[i][j - 1] = dp[i - 1][j];
		}

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][t[i]] = max(dp[i][t[i]], max(dp[i-1][1] + p[i],dp[i-1][0] + p[i]));
	}
	
	res = max(dp[n][0], dp[n][1]);

	printf("%d\n", res);

	return 0;
}