#include <iostream>
#include <vector>
using namespace std;

int dp[12] = { 0, };
vector<int> arr;

int main()
{

	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = dp[2] + dp[1] + 1;

	int i;
	for (i = 4; i < 12; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for (i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}

	for (i = 0; i < arr.size(); i++)
	{
		cout << dp[arr[i]] << endl;
	}


	return 0;
}