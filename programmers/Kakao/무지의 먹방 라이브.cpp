#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct food {
	int num;
	int t;
}food;

bool cmp1(food a, food b)
{
	return a.t > b.t;
}

bool cmp2(food a, food b)
{
	return a.num < b.num;
}


int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int check = 0;
	int temp = 0;
	vector<food> food_list;
	for (int i = 0; i < food_times.size(); i++)
	{
		food insert;
		insert.num = i + 1;
		insert.t = food_times[i];
		food_list.push_back(insert);
	}

	sort(food_list.begin(), food_list.end(), cmp1);

	while (food_list.size() != 0)
	{
		food search = food_list[food_list.size() - 1];
		if (food_list.size() * (search.t - temp) <= k)
		{
			k = k - (long long)(food_list.size() * (search.t - temp));
			temp = temp + (search.t - temp);
			food_list.pop_back();
		}
		else
		{
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		answer = -1;
	}
	else
	{
		sort(food_list.begin(), food_list.end(), cmp2);
		int idx;
		if (k < food_list.size())
		{
			idx = k;
		}
		else
		{
			idx = k % food_list.size();
		}
		answer = food_list[idx].num;
	}
	return answer;
}