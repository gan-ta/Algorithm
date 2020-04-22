#include <cstdio>
#include <algorithm>
using namespace std;

int dp[3][100001] = {0,};
int sticker[2][100001] = {0,};

int main()
{
	int t;

	scanf("%d", &t);

	int i,j,k;
	for (i = 0; i < t; i++)
	{
		int n;
		scanf("%d", &n);

		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < n; k++)
			{
				scanf("%d", &sticker[j][k]);
			}
		}

		for (j = 0; j < n; j++)
		{
			if (j == 0)
			{
				dp[0][j] = sticker[0][j];
				dp[1][j] = sticker[1][j];
				dp[2][j] = 0;
			}
			else
			{
				dp[0][j] = max(dp[1][j - 1] + sticker[0][j],dp[2][j-1] + sticker[0][j]);
				dp[1][j] = max(dp[0][j - 1] + sticker[1][j], dp[2][j - 1] + sticker[1][j]);
				dp[2][j] = max(dp[0][j - 1], dp[1][j - 1]);
			}
		}

		int result = max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);

		printf("%d\n", result);
	}
	return 0;
}