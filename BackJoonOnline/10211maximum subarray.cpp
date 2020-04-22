#include <iostream>
using namespace std;
int num[1001];
int maxEnding[1001];

int main()
{
	int maxSoFar;
	int T;
	int i, j;
	int N;
	cin >> T;
	for (i = 0; i < T; i++)
	{
		cin >> N;
		for (j = 0; j < N; j++)
		{
			cin >> num[j];
		}

		maxEnding[0] = num[0];
		maxSoFar = num[0];

		for (j = 1; j < N; j++)
		{
			if (maxEnding[j - 1] + num[j] > num[j])
			{
				maxEnding[j] = maxEnding[j - 1] + num[j];
			}
			else
			{
				maxEnding[j] = num[j];
			}

			if (maxSoFar < maxEnding[j])
			{
				maxSoFar = maxEnding[j];
			}
		}
		cout << maxSoFar << endl;
	}
	return 0;
}