#include <iostream>
#include <vector>
using namespace std;

int num[1121] = { 0, }; 
vector<int> cand;

int dp[1121][15];


int main()
{
	int T;
	cin >> T;
	int i, j, k;

	
	num[0] = 1;
	num[1] = 1;
	for (i = 2; i * i <= 1120; i++)
	{
		for (j = i + 1; j <= 1120; j++)
		{
			if (j % i == 0)
			{
				num[j] = 1;
			}
		}
	}

	for (i = 2; i <= 1120; i++)
	{
		if (num[i] == 0)
		{
			cand.push_back(i);
		}
	}

	dp[0][0] = 1;

	for (i = 0; i < cand.size(); i++)
	{
		for (j = 1120; j >= cand[i]; j--)
		{
			for (k = 1; k <= 14; k++)
			{
				dp[j][k] += dp[j - cand[i]][k - 1];
			}
		}
	}

	int a, b;
	for (i = 0; i < T; i++)
	{
		cin >> a;
		cin >> b;
		cout << dp[a][b] << endl;
	}
	return 0;
}
