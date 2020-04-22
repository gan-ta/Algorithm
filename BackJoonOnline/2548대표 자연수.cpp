#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int dp[20001] = { 0, }; 

int main()
{
	int N;
	int i, j;
	int temp;
	int index;
	cin >> N;
	arr.push_back(0);
	for (i = 1; i <= N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	for (i = 1; i <= N; i++)
	{
		dp[1] += arr[i] - arr[1];
	}

	for (i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] - (N - i + 1) * (arr[i] - arr[i - 1]) + (i - 1) * (arr[i] - arr[i - 1]);
	}

	index = 1;
	for (i = 2; i <= N; i++)
	{
		if (dp[index] > dp[i])
		{
			index = i;
		}
	}
	cout << arr[index] << endl;

	return 0;
}

