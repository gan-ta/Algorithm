#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool cmp(char a, char b)
{
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	string N;
	cin >> N;

	int sum = 0;
	bool check = false;

	for (int i = 0; i < N.size(); i++)
	{
		sum += (N[i] - '0');
		if ((N[i] - '0') == 0)
		{
			check = true;
		}
	}

	if (sum % 3 != 0)
	{
		cout << -1 << endl;
	}
	else if (check == false)
	{
		cout << -1 << endl;
	}
	else
	{
		sort(N.begin(), N.end(), cmp);
		cout << N << endl;
	}

	return 0;
}