#include <iostream>
#include <vector>
using namespace std;

int num[1001];
int loc[1001];
vector<int> res;
vector<int> co;

int main()
{
	int N;
	int i;
	int front, rear, mid;
	int bound;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	res.push_back(-1);

	for (i = 1; i <= N; i++)
	{
		front = 0;
		rear = res.size() - 1;
		bound = res.size();
		while (front <= rear)
		{
			mid = (front + rear) / 2;
			if (num[i] <= res[mid])
			{
				bound = mid;
				rear = mid - 1;
			}
			else
			{
				front = mid + 1;
			}
		}
		loc[i] = bound;

		if (bound == res.size())
		{
			res.push_back(num[i]);
		}
		else
		{
			res[bound] = num[i];
		}
	}

	int check = res.size() - 1;
	cout << res.size() - 1 << endl;
	for (i = N; i >= 1; i--)
	{
		if (loc[i] == check)
		{
			co.push_back(num[i]);
			check--;
		}
	}

	for (i = co.size() - 1; i >= 0; i--)
	{
		cout << co[i] << " ";
	}
	cout << endl;
	return 0;
}