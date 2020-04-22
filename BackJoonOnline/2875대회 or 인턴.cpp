#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int team = 0;
	int total = n + m - k;

	while (n > 1 && m > 0 && total > 2)
	{
		n -= 2;
		m -= 1;
		total -= 3;
		team++;
	}

	cout << team << endl;

	return 0;
}