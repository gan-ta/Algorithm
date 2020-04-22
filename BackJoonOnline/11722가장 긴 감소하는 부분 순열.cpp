#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1001];
vector<int> result;

int main()
{
	int N;
	int i;
	int check;
	int front, rear, mid;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	result.push_back(2000);

	for (i = 1; i <= N; i++)
	{
		front = 0;
		rear = result.size() - 1;
		check = result.size();
		while (front <= rear)
		{
			mid = (front + rear) / 2;
			if (result[mid] > arr[i])
			{
				front = mid + 1;
			}
			else
			{
				rear = mid - 1;
				check = mid;
			}
		}
		if (check == result.size())
		{
			result.push_back(arr[i]);
		}
		else
		{
			result[check] = arr[i];
		}
	}
	cout << result.size() - 1 << endl;
	return 0;
}