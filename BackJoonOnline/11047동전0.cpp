#include<iostream>
using namespace std;

int coin[11];

int N;
int aim;
int cnt = 0;

int main()
{
	int i;

	cin >> N;
	cin >> aim;
	for (i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}

	for (i = N; i >= 1; i--)
	{
		while (aim >= coin[i])
		{
			aim = aim - coin[i];
			cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}