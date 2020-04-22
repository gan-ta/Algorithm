#include <cstdio>
using namespace std;

unsigned int dp[1000001];

int main()
{
	int t;
	int i;


	scanf("%d", &t);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (i = 4; i < 1000001; i++)
	{
		dp[i] = ((dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009);
	}

	for (i = 0; i < t; i++)
	{
		int num;

		scanf("%d", &num);

		printf("%d\n", dp[num]);
	}

	return 0;
}