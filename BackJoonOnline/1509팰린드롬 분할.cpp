#include <iostream>
#include <cstring>
using namespace std;

char arr[2501];
bool chk[2501][2501];
int dp[2501];

int main()
{
	int i, j;
	int length = 0;
	int min;
	cin >> arr;
	length = strlen(arr);
	for (i = 0; i < length; i++)
	{
		for (j = 0; (j + i) < length; j++)
		{
			if (arr[j] == arr[j + i])
			{
				if (j + 1 > j + i - 1)
				{
					chk[j][j + i] = true;
				}
				else
				{
					if (chk[j + 1][j + i - 1] == true)
					{
						chk[j][j + i] = true;
					}
					else
					{
						chk[j][j + i] = false;
					}
				}
			}
		}
	}

	for (i = 0; i < length; i++)
	{
		if (i == 0)
		{
			dp[i] = 1;
		}
		else
		{
			min = dp[i - 1] + 1;
			for (j = i - 1; j >= 0; j--)
			{
				if (chk[j][i] == true)
				{
					if (min > dp[j - 1] + 1)
					{
						min = dp[j - 1] + 1;
					}
				}
			}
			dp[i] = min;
		}
	}

	cout << dp[length - 1] << endl;

	return 0;
}