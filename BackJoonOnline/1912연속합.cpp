#include <iostream>
using namespace std;
int num[100001];
int maxEnding[100001];


int main()
{
	int n;
	int maxSoFar;
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	maxEnding[0] = num[0];
	maxSoFar = num[0];
	for (i = 1; i < n; i++)
	{
		if (num[i] + maxEnding[i - 1] > num[i])
		{
			maxEnding[i] += num[i] + maxEnding[i - 1];
		}
		else
		{
			maxEnding[i] = num[i];
		}
		if (maxSoFar < maxEnding[i])
		{
			maxSoFar = maxEnding[i];
		}
	}

	cout << maxSoFar << endl;

	return 0;
}