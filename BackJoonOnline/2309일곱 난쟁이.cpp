#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fake;
vector<int> real;

int main()
{
	int i, j;
	int temp;
	int total = 0;
	int temp_total = 0;
	int m = 0;
	int check = 0;
	int m1, m2;

	for (i = 0; i < 9; i++)
	{
		cin >> temp;
		fake.push_back(temp);
		total += temp;
	}

	temp_total = total;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			m = fake[i] + fake[j];
			temp_total -= m;
			if (temp_total == 100)
			{
				check = 1;
				m1 = i;
				m2 = j;
				break;
			}
			temp_total = total;
		}
		if (check == 1) break;
	}

	for (i = 0; i < 9; i++)
	{
		if (i != m1 && i != m2)
		{
			real.push_back(fake[i]);
		}
	}

	sort(real.begin(), real.end());

	for (i = 0; i < 7; i++)
	{
		cout << real[i] << endl;
	}


	return 0;
}