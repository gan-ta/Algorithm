#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[110];
char str2[110];
char str3[110];

int dp[110][110][110] = { 0, };

int main()
{
	int a, b, c;
	int i, j, k;
	cin >> str1;
	cin >> str2;
	cin >> str3;

	a = strlen(str1);
	b = strlen(str2);
	c = strlen(str3);


	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			for (k = 0; k < c; k++)
			{
				if ((str1[i] == str2[j]) && (str2[j] == str3[k]))
				{
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				}
				else
				{
					dp[i + 1][j + 1][k + 1] = max({ dp[i][j + 1][k + 1] , dp[i + 1][j][k + 1] ,dp[i + 1][j + 1][k] });
				}
			}
		}
	}


	cout << dp[a][b][c] << endl;
	return 0;
}