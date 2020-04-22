#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char str1[1001];
char str2[1001];

int dp[1001][1001];

int main()
{
	int a, b;
	int i, j;
	cin >> str1;
	cin >> str2;

	a = strlen(str1);
	b = strlen(str2);

	for (i = 0; i <= a; i++)
	{
		dp[i][0] = i;
	}

	for (j = 0; j <= b; j++)
	{
		dp[0][j] = j;
	}

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i + 1][j + 1] = dp[i][j];
			}
			else
			{
				dp[i + 1][j + 1] = min({ dp[i + 1][j] + 1,dp[i][j + 1] + 1,dp[i][j] + 1 });
			}
		}
	}

	cout << dp[a][b] << endl;
	return 0;
}