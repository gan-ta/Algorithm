#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001];


int main()
{
	int i, j;
	int N;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		dp[i] = i;
		for (j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N] << endl;
	return 0;
}

