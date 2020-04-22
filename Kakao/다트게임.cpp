#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

typedef struct info {
	int score;
	int bonus;
	int star;
	int acha;
}info;

int solution(string dartResult) {
	int answer = 0;
	int idx = 0;
	vector<info> info_list;
	int i;

	while (idx != dartResult.size())
	{
		info insert;
		insert.star = 0;
		insert.acha = 0;
		if (!isalpha(dartResult[idx]))
		{
			if (!isalpha(dartResult[idx + 1]))
			{
				insert.score = 10;
				idx += 2;
			}
			else
			{
				insert.score = (int)dartResult[idx] - 48;
				idx += 1;
			}
		}

		if (dartResult[idx] == 'S')
		{
			insert.bonus = 1;
		}
		else if (dartResult[idx] == 'D')
		{
			insert.bonus = 2;
		}
		else if (dartResult[idx] == 'T')
		{
			insert.bonus = 3;
		}

		idx += 1;

		if (dartResult[idx] == '*')
		{
			if (info_list.size() == 0)
			{
				insert.star = 1;
			}
			else
			{
				insert.star = 1;
				info_list.back().star += 1;
			}
			idx += 1;
		}
		else if (dartResult[idx] == '#')
		{
			insert.acha = 1;
			idx += 1;
		}
		info_list.push_back(insert);
	}
	for (i = 0; i < info_list.size(); i++)
	{
		info search = info_list[i];
		int temp;
		temp = pow(search.score, search.bonus);
		if (search.star != 0)
		{
			temp = temp * (2 * search.star);
		}
		if (search.acha != 0)
		{
			temp = temp * (-1 * search.acha);
		}
		answer += temp;

	}

	return answer;
}