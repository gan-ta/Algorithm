#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct page {
	int num;
	int basis, link;
	double score;
}page;

bool cmp(const page& a, const page& b)
{
	if (a.score == b.score)
	{
		return a.num < b.num;
	}
	else
	{
		return a.score > b.score;
	}
}

int solution(string word, vector<string> pages) {
	int answer = 0;
	int i;
	map<string, int> url_table;
	vector<page> page_list;
	int word_size = word.size();

	transform(word.begin(), word.end(), word.begin(), ::tolower);

	for (i = 0; i < pages.size(); i++)
	{
		string& s = pages[i];
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int basis_cnt = 0;
		int link_cnt = 0;
		int lpos = 0, rpos = 0, mid = 0;
		while (mid <= lpos)
		{
			lpos = s.find("<meta", lpos + 1);
			rpos = s.find(">", lpos);
			mid = s.rfind("https://", rpos);
		}
		rpos = s.find("\"", mid);
		string url = s.substr(mid, rpos - mid);
		url_table[url] = i;

		lpos = 0;
		rpos = 0;

		lpos = s.find("<body>", 0);
		while (1)
		{
			lpos = s.find(word, lpos + 1);
			if (lpos == string::npos) break;

			if (!isalpha(s[lpos - 1]) && !isalpha(s[lpos + word_size]))
			{
				basis_cnt++;
			}
		}

		lpos = s.find("<body>", 0);
		while (1)
		{
			lpos = s.find("<a href=", lpos + 1);
			if (lpos == string::npos) break;

			link_cnt++;
		}
		page_list.push_back({ i,basis_cnt,link_cnt,(double)basis_cnt });
	}

	for (i = 0; i < pages.size(); i++)
	{
		string& s = pages[i];
		string link_url;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int lpos = 0, rpos = 0, mid = 0;

		while (1)
		{
			lpos = s.find("<a href=", lpos + 1);
			if (lpos == string::npos) break;

			mid = s.find("https://", lpos);
			rpos = s.find("\"", mid);
			link_url = s.substr(mid, rpos - mid);

			map<string, int>::iterator it = url_table.find(link_url);
			if (it != url_table.end())
			{
				page_list[it->second].score += (double)page_list[i].basis / (double)page_list[i].link;
			}
		}
	}

	sort(page_list.begin(), page_list.end(), cmp);
	answer = page_list[0].num;

	return answer;
}