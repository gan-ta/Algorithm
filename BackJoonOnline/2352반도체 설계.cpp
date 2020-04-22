#include <iostream>
#include <algorithm>
using namespace std;

int w[40001];
int cache[40001];

int main()
{
	int i;
	int n;
	int size;
	int it;

	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	
	cache[1] = w[1];
	size = 1;

	for (i = 2; i <= n; i++)
	{
		
		if (cache[size] < w[i])
		{
			size++;
			cache[size] = w[i];
			continue;
		}

		it = lower_bound(cache + 1, cache + size + 1, w[i]) - cache;
		cache[it] = w[i];
	}

	cout << size << endl;

	return 0;
}