#include <iostream>
#include <algorithm>
using namespace std;

int K[101];
int S[101];

int dp[101][10001] = { 0, };

int main()
{
	int n, t;
	cin >> n;
	cin >> t;
	int i, j;
	for (i = 0; i < n; i++)
	{
		cin >> K[i];
		cin >> S[i];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= t; j++)
		{
			if (j - K[i - 1] < 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - K[i - 1]] + S[i - 1]);
			}
		}
	}

	cout << dp[n][t] << endl;
	return 0;
}


