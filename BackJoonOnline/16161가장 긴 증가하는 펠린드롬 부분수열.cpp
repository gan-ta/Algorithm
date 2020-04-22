#include <iostream>
using namespace std;
int arr[100002] = { 0, };

int main()
{
	int N;
	int i;
	int j = 1;
	int temp = 1;
	int max = 1;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}


	for (i = 1; i <= N; i++)
	{
		while ((i - j >= 1) && (i + j <= N) && (arr[i - j] == arr[i + j]) && (arr[i - j] < arr[i - j + 1]))
		{
			temp = temp + 2;
			j++;
		}
		if (max < temp)
		{
			max = temp;
		}
		j = 1;
		temp = 1;
		if ((arr[i] == arr[i + 1]) && ((i + 1) <= N))
		{
			temp = 2;
			while ((i - j >= 1) && (i + j + 1 <= N) && (arr[i - j] == arr[i + j + 1]) && (arr[i - j] < arr[i - j + 1]))
			{
				temp = temp + 2;
				j++;
			}
			if (max < temp)
			{
				max = temp;
			}
			j = 1;
			temp = 1;
		}
	}
	cout << max << endl;
	return 0;
}