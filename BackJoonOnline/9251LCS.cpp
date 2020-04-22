#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[1001];
char str2[1001];
int d[1001][1001] = { 0, };

int main()
{

	int i, j;
	cin >> str1;
	cin >> str2;
	int m = strlen(str1);
	int n = strlen(str2);

	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}

	cout << d[m][n] << endl;
	return 0;
}