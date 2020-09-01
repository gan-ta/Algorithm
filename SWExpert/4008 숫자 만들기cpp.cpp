#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<int> oper;
int num[13] = { 0, };

int res1 = -100000001;
int res2 = 100000001;


int main()
{
	int T;
	int t;
	int i, j;
	int temp;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		oper.clear();
		memset(num, 0, sizeof(num));
		res1 = -100000001;
		res2 = 100000001;
		scanf("%d", &n);

		for (i = 0; i < 4; i++)
		{
			scanf("%d", &temp);
			for (j = 0; j < temp; j++)
			{
				oper.push_back(i);
			}
		}

		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}


		sort(oper.begin(), oper.end());

		do {
			int temp_result = num[0];
			for (i = 0; i < oper.size(); i++)
			{
				if (oper[i] == 0) temp_result += num[i + 1];
				else if (oper[i] == 1) temp_result -= num[i + 1];
				else if (oper[i] == 2) temp_result = temp_result * num[i + 1];
				else if (oper[i] == 3) temp_result = temp_result / num[i + 1];
			}


			if (res1 < temp_result) res1 = temp_result;
			if (res2 > temp_result) res2 = temp_result;

		} while (next_permutation(oper.begin(), oper.end()));

		printf("#%d %d\n", t + 1, res1 - res2);
	}

	return 0;
}