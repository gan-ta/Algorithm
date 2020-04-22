#include <iostream>
using namespace std;

int n;
int b, c;

int room[1000001];

int main()
{
	int i;
	long long res = 0;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> room[i];
	}

	cin >> b >> c;

	long long temp;
	for (i = 0; i < n; i++)
	{
		room[i] -= b;
		res++;

		temp = room[i] / c;


		if (room[i] > 0)
		{
			if (room[i] % c == 0)
			{
				res += temp;
			}
			else
			{
				res += temp + 1;
			}
		}
	}

	cout << res << endl;
	return 0;
}