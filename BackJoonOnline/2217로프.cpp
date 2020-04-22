#include<iostream>
#include<algorithm>
#include<functional>
#include <numeric>
using namespace std;

int N;
int rope[100001] = { 0, };

int main()
{
	
	int i;
	int total = 0;
	int cnt = 0;
	int res = 0;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> rope[i];
	}


	sort(rope + 1, rope + N + 1, greater<int>());


	for (i = 1; i <= N; i++)
	{
		cnt++;
		if (res < cnt * rope[i])
		{
			res = cnt * rope[i];
		}
	}

	cout << res << endl;

	return 0;
}
