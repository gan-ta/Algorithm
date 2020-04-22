#include <iostream>
#include <deque>
#include <vector>
#include<algorithm>
using namespace std;

int num[500001] = { 0, };
long long dp[500001] = { 0, };
deque<int> candy;
vector<vector<int>> price;
vector<int> vtemp;


int main()
{
	int N;
	int i, j, k;
	int sum = 0;
	int temp;
	int prev;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> temp;
		candy.push_back(temp);
		sum += temp;
	}

	sort(candy.begin(), candy.end());


	num[0] = 1;
	num[1] = 1;
	for (i = 2; i * i <= sum; i++)
	{
		for (j = i + 1; j <= sum; j++)
		{
			if (j % i == 0)
			{
				num[j] = 1;
			}
		}
	}



	int cnt = 1;
	prev = candy.front();
	candy.pop_front();
	while (1)
	{
		if (!candy.empty())
		{
			while (candy.front() == prev) 
			{
				prev = candy.front();
				candy.pop_front();
				cnt++;
				if (candy.empty())
				{
					break;
				}
			}
		}
		for (i = 0; i <= cnt; i++)
		{
			vtemp.push_back(prev * i);
		}
		price.push_back(vtemp);
		vtemp.clear();
		if (candy.empty())
		{
			break;
		}
		prev = candy.front();
		candy.pop_front();
		cnt = 1;
	}

	int max = 0;
	long long long_temp = 0;
	dp[0] = 1;
	for (i = 0; i < price.size(); i++)
	{
		for (j = max; j >= 0; j--)
		{
			if (dp[j] != 0)
			{
				long_temp = dp[j];
				dp[j] = 0;
				for (k = 0; k < price[i].size(); k++)
				{
					dp[j + price[i][k]] += long_temp;
				}
			}
		}
		
		max += price[i][price[i].size() - 1];
	}


	
	long long count = 0;
	for (i = 0; i <= sum; i++)
	{
		if (dp[i] != 0)
		{
			if (num[i] == 0)
			{
				count += dp[i];
			}
		}
	}

	cout << count << endl;

	return 0;
}