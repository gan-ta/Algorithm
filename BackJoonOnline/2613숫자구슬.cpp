#include <iostream>
using namespace std;
int arr[301];
int cut_sum[301];
int cut[301];
int count = 0;
int N;
int ind = 0;


int group_check(int num);
void func(int num);

int main()
{
	int M;
	cin >> N;
	cin >> M;
	int i;
	int sum = 0;
	int front, rear, mid;
	int check;
	int bound;
	for (i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	front = 1;
	rear = sum;
	bound = rear;
	while (front <= rear)
	{
		mid = (front + rear) / 2;
		check = group_check(mid);
		if (check > M)
		{
			front = mid + 1;
		}
		else if (check < M)
		{
			rear = mid - 1;

		}
		else
		{
			if (front == rear)
			{
				front++;
			}
			rear = mid;
		}
		bound = rear;
	}

	func(bound);

	
	if (group_check(bound) != M)
	{
		int cnt = group_check(bound) - M;
		int check;
		while (cnt != 0)
		{
			int min = 100 * N;
			for (i = 0; i < ind; i++)
			{
				if (min > cut_sum[i] + cut_sum[i + 1])
				{
					min = cut_sum[i] + cut_sum[i + 1];
					check = i;
				}
			}
			cut_sum[check] = cut_sum[check] + cut_sum[check + 1];
			cut[check] = cut[check] + cut[check + 1];
			for (i = check + 1; i < ind; i++)
			{
				cut_sum[i] = cut_sum[i + 1];
				cut[i] = cut[i + 1];
			}
			cnt--;
			ind--;
		}

	}

	int a = -100;
	for (i = 0; i <= ind; i++)
	{
		if (a < cut_sum[i])
		{
			a = cut_sum[i];
		}
	}
	cout << a << endl;
	for (i = 0; i <= ind; i++)
	{
		cout << cut[i] << " ";
	}
	cout << endl;
	return 0;
}

int group_check(int num)
{
	int res = 1;
	int i;
	int sum = 0;
	sum = arr[1];
	for (i = 2; i <= N; i++)
	{
		sum += arr[i];
		if (sum > num)
		{
			sum = arr[i];
			res++;
		}
	}
	return res;
}

void func(int num)
{
	ind = 0;
	int i;
	int sum = 0;
	int count = 1;
	sum = arr[1];

	for (i = 2; i <= N; i++)
	{
		sum += arr[i];
		if (sum > num)
		{
			cut_sum[ind] = sum - arr[i];
			cut[ind++] = count;
			count = 1;
			sum = arr[i];
		}
		else
		{
			count++;
		}
	}
	cut_sum[ind] = sum;
	cut[ind] = count;

}