#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	int i, j;
	vector<vector<char>> map1;
	vector<vector<char>> map2;
	vector<char> temp;
	vector<char> re;

	for (i = 0; i < n; i++)
	{
		int search = arr1[i];
		for (j = 0; j < n; j++)
		{
			if ((search & 1) == 1)
			{
				temp.push_back('#');
			}
			else
			{
				temp.push_back(' ');
			}
			search = search >> 1;
		}

		for (j = temp.size() - 1; j >= 0; j--)
		{
			re.push_back(temp[j]);
		}
		map1.push_back(re);

		temp.clear();
		re.clear();

		search = arr2[i];
		for (j = 0; j < n; j++)
		{
			if ((search & 1) == 1)
			{
				temp.push_back('#');
			}
			else
			{
				temp.push_back(' ');
			}
			search = search >> 1;
		}

		for (j = temp.size() - 1; j >= 0; j--)
		{
			re.push_back(temp[j]);
		}
		map2.push_back(re);
		temp.clear();
		re.clear();
	}

	string s_temp = "";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (map1[i][j] == '#' || map2[i][j] == '#')
			{
				s_temp += "#";
			}
			else
			{
				s_temp += " ";
			}
		}
		answer.push_back(s_temp);
		s_temp = "";
	}

	return answer;
}