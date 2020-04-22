#include <iostream>
using namespace std;

int price[101];
int num[101];
int dp[10001];
int temp_dp[10001];

int main()
{
	int T;
	int k;
	cin >> T;
	cin >> k;
	int i, j, l;
	int temp_price;
	for (i = 0; i < k; i++)
	{
		cin >> price[i];
		cin >> num[i];
	}

	temp_dp[0] = 1;
	dp[0] = 1;

	for (i = 0; i < k; i++)
	{

		
		for (j = 0; j <= T; j++)
		{
			temp_dp[j] = dp[j];
		}


		for (j = num[i]; j >= 1; j--)
		{
			temp_price = price[i] * j;
			for (l = T; l >= temp_price; l--)
			{
				dp[l] += temp_dp[l - temp_price];
			}
		}
	}

	cout << dp[T] << endl;

	return 0;
}