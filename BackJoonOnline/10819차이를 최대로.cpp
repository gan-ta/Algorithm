#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[8];
int n;


int calculate()
{
	int i;
	int res = 0;
	for (i = 0; i < n - 1; i++)
	{
		res += abs(arr[i] - arr[i + 1]);
	}

	return res;
}

int main()
{
	int i;
	int res = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	while (1)
	{
		res = max(res, calculate());

		if (next_permutation(arr, arr + n) == false) break;
	}

	printf("%d\n", res);

	return 0;
}