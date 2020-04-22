#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int num;
	int d1;
	int d2;
	int aim = 4;

	scanf("%d", &num);

	while (aim != num + 1 && num != 1 && num != 2 && num != 3)
	{
		if (aim % 3 == 0) d1 = aim / 3;
		else d1 = -1;

		if (aim % 2 == 0) d2 = aim / 2;
		else d2 = -1;

		if (d1 != -1 && d2 != -1)
		{
			dp[aim] = min(min(dp[d1] + 1, dp[d2] + 1), dp[aim - 1] + 1);
		}
		else if (d1 == -1 && d2 != -1)
		{
			dp[aim] = min(dp[d2] + 1, dp[aim - 1] + 1);
		}
		else if (d1 != -1 && d2 == -1)
		{
			dp[aim] = min(dp[d1] + 1, dp[aim - 1] + 1);
		}
		else
		{
			dp[aim] = dp[aim - 1] + 1;
		}
		aim++;

	}

	printf("%d\n", dp[num]);

	return 0;
}