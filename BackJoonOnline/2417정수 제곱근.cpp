#include <iostream>
using namespace std;

const int INF = 1e10;

int main()
{
	long long n;
	cin >> n;
	long long l = 0;
	long long r = INF * 4ll;
	long long ans = 0;
	unsigned long long m;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (m * m >= n)
		{
			ans = m;
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
	return 0;
}