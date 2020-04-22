#include<iostream>
#include<algorithm>
using namespace std;

int N;
int time[1001];
int res = 0;

int main()
{
	int i, j;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> time[i];
	}
	sort(time + 1, time + N + 1);


	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i; j++)
		{
			res += time[j];
		}
	}

	cout << res << endl;

}