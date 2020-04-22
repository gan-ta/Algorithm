#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int i, j;
	int start = 0;
	string buffer = "";
	int len = s.size();
	vector<int> same;
	int cnt = 0;
	for (i = 1; i <= s.size(); i++)
	{
		start = 0;
		len = s.size();
		buffer = "";
		cnt = 0;
		same.clear();
		while (1)
		{
			if (start > s.size() - 1) break;

			if (buffer.compare(s.substr(start, i)) == 0)
			{
				cnt++;
			}
			else
			{
				same.push_back(cnt);
				cnt = 0;
				buffer = s.substr(start, i);
			}
			start = start + i;
		}
		if (cnt != 0) same.push_back(cnt);
		for (j = 0; j < same.size(); j++)
		{
			len -= (same[j] * i);
			if (same[j] >= 1 && same[j] < 9)
			{
				len += 1;
			}
			else if (same[j] >= 9 && same[j] < 99)
			{
				len += 2;
			}
			else if (same[j] >= 99 && same[j] < 999)
			{
				len += 3;
			}
			else if (same[j] >= 999)
			{
				len += 4;
			}
		}
		if (answer == 0)
		{
			answer = len;
		}
		else if (answer > len)
		{
			answer = len;
		}
	}
	return answer;
}