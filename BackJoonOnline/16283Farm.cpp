#include <iostream>
using namespace std;

int main()
{
	int a, b, n, w;
	cin >> a >> b >> n >> w;

	int i;
	int a1, a2;
	int check;
	int cnt = 0;

	for (i = 1; i < n; i++)
	{
		check = a * i + b * (n - i);
		if (check == w)
		{
			cnt++;
			a1 = i;
			a2 = n - i;
		}
	}

	if (cnt == 1)
	{
		cout << a1 << " " << a2 << endl;
	}
	else
	{
		cout << -1 << endl;
	}

	return 0;
}