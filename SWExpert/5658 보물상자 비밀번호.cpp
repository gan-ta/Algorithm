#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<int> group;
string temp;


int s_to_i(string temp)
{
	int i;
	int multi = 1;
	int res = 0;
	for (i = temp.size() - 1; i >= 0; i--)
	{
		if (temp[i] >= 65 && temp[i] <= 90) {
			res += (temp[i] - 55) * multi;
		}
		else {
			res += (temp[i] - 48) * multi;
		}
		multi = multi * 16;
	}

	return res;
}

int main()
{
	int t;
	int n;
	int k;
	int i, j, m, z;
	int group_num = 0;
	int cur = 0;
	string search = "";
	int check = 0;
	int ans = 0;
	int check_num = -1;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{

		scanf("%d", &n);
		scanf("%d", &k);
		group_num = n / 4;
		cur = 0;
		search = "";
		ans = 0;
		check_num = -1;
		check = 0;
		group.clear();
		cin >> temp;

		for (m = 0; m < group_num; m++)
		{
			cur = m;
			for (j = 0; j < temp.size(); j++)
			{
				search += temp[(cur + check) % n];
				check++;
				if (check == group_num)
				{
					cur += group_num;
					check = 0;
					group.push_back(s_to_i(search));
					search = "";
				}
			}


		}


		sort(group.begin(), group.end(), greater<int>());

		check = 0;

		for (j = 0; j < group.size(); j++)
		{
			if (check_num != group[j])
			{
				check_num = group[j];
				check++;
			}

			if (check == k)
			{
				printf("#%d %d\n", i + 1, check_num);
				break;
			}
		}
	}


	return 0;
}