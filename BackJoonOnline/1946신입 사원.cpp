#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> r[100001];

int main()
{
	int t, n;
	int i, j, k;

	cin >> t;

	for (i = 0; i < t; i++)
	{
		int res = 0;
		cin >> n;


		for (j = 0; j < n; j++)
		{
			cin >> r[j].first;
			cin >> r[j].second;
		}

		sort(r, r + n);

		int second_rank = r[0].second;

		for (j = 0; j < n; j++)
		{
			if (r[j].second <= second_rank)
			{
				res++;
				second_rank = r[j].second;
			}


		}

		cout << res << endl;

	}
	return 0;
}