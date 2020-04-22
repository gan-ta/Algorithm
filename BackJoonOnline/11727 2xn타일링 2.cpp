#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001];

int main()
{
	int num;
	int aim = 3;
	dp[1] = 1;
	dp[2] = 3;
	scanf("%d", &num);
	while (aim != num + 1 && num != 1 && num != 2)
	{
		dp[aim] = ((dp[aim - 2] * 2) + dp[aim - 1]) % 10007;
		aim++;
	}

	printf("%d\n", dp[num]);
	return 0;
}