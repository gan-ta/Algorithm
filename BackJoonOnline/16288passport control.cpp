#include <iostream>
using namespace std;

int arr[101] = { 0, };

int main()
{
	int n, k;

	cin >> n >> k;

	int i, j;
	int temp;

	for (i = 1; i <= n; i++)
	{
		cin >> temp;
		for (j = 1; j <= n; j++)
		{
			if (temp > arr[j])
			{
				arr[j] = temp;
				break;
			}
		}

		if (j == k + 1)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}