#include<iostream>
using namespace std;
int main()
{
	long long aim;
	long long ans;
	long long sum = 0;
	int n;

	int i, j;

	cin >> aim;

	for (i = 1;; i++)
	{
		ans = i;
		n = i + 1;
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				sum += n;
				ans += sum;
			}
			else
			{
				sum = sum * 2;
				ans += sum;
			}
		}
		if (ans >= aim)break;

		sum = 0;
	}
	cout << i << endl;
	return 0;
}