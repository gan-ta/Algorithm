#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001];
std::vector<int> result;



int main()
{
	int N;
	int i;
	int front, rear, mid;
	cin >> N;
	result.push_back(-1);
	for (i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	for (i = 1; i <= N; i++)
	{

		auto check = lower_bound(result.begin(), result.end(), arr[i]);
		if ((check - result.begin()) == result.size())
		{
			result.push_back(arr[i]);
		}
		else
		{
			result[check - result.begin()] = arr[i];
		}

	}
	cout << result.size() - 1 << endl;

	return 0;
}