#include <iostream>
#include <vector>
using namespace std;
int num[5000];

typedef struct d {
	int a;
	int b;
	int sum;
}d;

vector<d> dp[800001];
int check[800001];

int main()
{
	int w, n;
	int i, j, k;
	cin >> w >> n;

	for (i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			d temp;
			temp.a = num[i];
			temp.b = num[j];
			temp.sum = num[i] + num[j];
			dp[temp.sum].push_back(temp);
			check[temp.sum] = 1;
		}
	}

	int res = 0;
	for (i = 1; i <= w / 2; i++)
	{
		if (check[i] == 1 && check[w - i] == 1)
		{
			for (j = 0; j < dp[i].size(); j++)
			{
				for (k = 0; k < dp[w - i].size(); k++)
				{
					if ((dp[i][j].a != dp[w - i][k].a) && (dp[i][j].a != dp[w - i][k].b) && (dp[i][j].b != dp[w - i][k].a) && (dp[i][j].b != dp[w - i][k].b))
					{
						res = 1;
						break;
					}
				}
				if (res == 1) break;
			}
		}
		if (res == 1) break;
	}

	if (res == 1) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}