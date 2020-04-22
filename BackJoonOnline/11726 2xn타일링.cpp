#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1001];

int main()
{
	int aim;
	scanf("%d", &aim);

	int num = 3;
	dp[1] = 1;
	dp[2] = 2;

	while (num != aim + 1 && aim != 1 && aim != 2)
	{
		dp[num] = (dp[num - 1] + dp[num - 2]) % 10007;
		num++;
	}

	printf("%d\n", dp[aim]);
	return 0;
}