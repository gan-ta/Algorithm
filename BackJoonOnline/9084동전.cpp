#include <iostream>
using namespace std;

int coin[21];


int main()
{
	int T;
	cin >> T;
	int i, j, k;
	int N;
	int aim;
	for (k = 0; k < T; k++)
	{
		int dp[10001] = { 0, };
		cin >> N;
		for (j = 0; j < N; j++)
		{
			cin >> coin[j];
		}

		cin >> aim;

		dp[0] = 1;
		for (i = 0; i < N; i++)
		{
			for (j = coin[i]; j <= aim; j++)
			{
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[aim] << endl;


	}
}