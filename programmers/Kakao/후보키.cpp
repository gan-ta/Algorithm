#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int count_bit(int num)
{
	int res = 0;
	while (num)
	{
		if (num & 1) res++;
		num = num >> 1;
	}
	return res;
}

bool cmp(int a, int b)
{
	int x = count_bit(a);
	int y = count_bit(b);

	return x > y;
}

bool check(vector<vector<string>> relation, int rowsize, int colsize, int group)
{
	int i, j, k;
	for (i = 0; i < rowsize - 1; i++)
	{
		for (j = i + 1; j < rowsize; j++)
		{
			bool isSame = true;
			for (k = 0; k < colsize; k++)
			{
				if ((group & 1 << k) == 0) continue;
				if (relation[i][k] != relation[j][k])
				{
					isSame = false;
					break;
				}
			}
			if (isSame) return false;
		}
	}
	return true;
}

int solution(vector<vector<string>> relation) {
	int answer = 0;
	int rowsize = relation.size();
	int colsize = relation.back().size();
	vector<int> candidate;

	for (int i = 1; i < 1 << colsize; i++)
	{
		if (check(relation, rowsize, colsize, i)) candidate.push_back(i);
	}

	sort(candidate.begin(), candidate.end(), cmp);

	while (!candidate.empty())
	{
		int temp = candidate.back();
		candidate.pop_back();
		answer++;
		for (vector<int>::iterator it = candidate.begin(); it != candidate.end();)
		{
			if ((temp & *it) == temp)
			{
				candidate.erase(it);
			}
			else
			{
				it++;
			}
		}
	}
	return answer;
}