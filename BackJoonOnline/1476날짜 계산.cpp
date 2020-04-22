#include <iostream>
using namespace std;

int rE, rS, rM;
int E = 1;
int S = 1;
int M = 1;

void add()
{
	E++;
	S++;
	M++;
	if (E == 16) E = 1;
	if (S == 29) S = 1;
	if (M == 20) M = 1;
}

int main()
{

	int i;
	int count = 1;
	cin >> rE;
	cin >> rS;
	cin >> rM;

	while (1)
	{
		if (E == rE && S == rS && M == rM) break;

		add();
		count++;
	}


	cout << count << endl;
	return 0;
}