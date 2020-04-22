#include <iostream>
using namespace std;

unsigned long long sum(unsigned long long x);

int main()
{
	int T;
	cin >> T;
	int i;
	unsigned long long brid;
	unsigned long long front, rear, mid;
	unsigned long long ans;
	for (i = 0; i < T; i++)
	{
		cin >> brid;
		front = 1;
		rear = brid;
		while (front <= rear)
		{
			mid = (front + rear) / 2;
			if (brid >= sum(mid))
			{
				ans = mid;
				front = mid + 1;
			}
			else
			{
				rear = mid - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

unsigned long long sum(unsigned long long x)
{
	return ((x + 1) * x) / 2;
}

