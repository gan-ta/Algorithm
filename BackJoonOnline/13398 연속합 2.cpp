#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];
int dp[2][100001];

int main()
{
	int n;
	int i;
	int mf;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	dp[0][0] = num[0];
	dp[0][1] = max(dp[0][0] + num[1], num[1]);
	dp[1][1] = num[1];
	mf = max({ dp[0][0] , dp[0][1], dp[1][1] });

	for (i = 2; i < n; i++)
	{
		dp[0][i] = max(dp[0][i - 1] + num[i], num[i]);
		dp[1][i] = max(dp[0][i - 2] + num[i], dp[1][i - 1] + num[i]);

		mf = max({ mf, dp[0][i], dp[1][i] });
	}

	cout << mf << endl;
	return 0;

}