#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int num1[100001];
int num2[100001];


vector<int>  result;


int main()
{
	int N;
	cin >> N;
	int i;
	int temp;
	for (i = 0; i < N; i++)
	{
		cin >> temp;
		num1[temp] = i;
	}
	for (i = 0; i < N; i++)
	{
		cin >> num2[i];
	}

	result.push_back(-1);

	for (i = 0; i < N; i++)
	{
		if (result.back() < num1[num2[i]])
		{
			result.push_back(num1[num2[i]]);
		}
		else
		{
			auto check = lower_bound(result.begin(), result.end(), num1[num2[i]]);
			result[check - result.begin()] = num1[num2[i]];
		}
	}
	cout << result.size() - 1 << endl;

	return 0;
}