#include <iostream>
#include <algorithm>
using namespace std;

int sum_apple[1502][1502] = { 0, };
int sum_banana[1502][1502] = { 0, };
int dp[1502][1502] = { 0, };

int main()
{
	int R, C;
	cin >> R >> C;
	int i, j;
	char name; 
	int temp; 
	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			cin >> name >> temp;
			sum_apple[i][j] = sum_apple[i][j - 1];
			sum_banana[i][j] = sum_banana[i - 1][j]; 
			if (name == 'A')
			{
				sum_apple[i][j] += temp;
			}
			else if (name == 'B')
			{
				sum_banana[i][j] += temp;
			}
		}
	}

	for (i = 1; i <= R; i++)
	{
		for (j = 1; j <= C; j++)
		{
			if ((i == 1) && (j == 1))
			{
				dp[i][j] = 0;
				continue;
			}
			else if (i == 1) 
			{
				dp[i][j] = dp[i][j - 1] + sum_banana[i - 1][j];
			}
			else if (j == 1) 
			{
				dp[i][j] = dp[i - 1][j] + sum_apple[i][j - 1];
			}
			else 
			{
				dp[i][j] = max(max(dp[i - 1][j - 1] + sum_apple[i][j - 1] + sum_banana[i - 1][j], dp[i][j - 1] + sum_banana[i - 1][j]), max(dp[i][j], dp[i - 1][j] + sum_apple[i][j - 1]));
			}
		}
	}

	cout << dp[R][C] << endl;
	return 0;
}