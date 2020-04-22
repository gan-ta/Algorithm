#include <iostream>
#include <algorithm>
using namespace std;

int dp[101];
int hp[21];
int happy[21];

int main()
{
	int N;
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++)
	{
		cin >> hp[i];
	}
	for (i = 0; i < N; i++)
	{
		cin >> happy[i];
	}

	for (i = 0; i < N; i++)
	{
		for (j = 100; j > hp[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}

	cout << dp[100] << endl;
	return 0;
}