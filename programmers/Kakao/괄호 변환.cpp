#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<char> buffer;

bool correct_check(string search)
{
	stack<char> test;
	int i;
	if (search.size() == 0) return true;

	if (search[0] == ')') return false;

	test.push(search[0]);

	for (i = 1; i < search.size(); i++)
	{
		if (test.empty()) return false;

		if (search[i] == ')')
		{
			test.pop();
		}
		else
		{
			test.push(search[i]);
		}
	}
	return true;
}

string dfs(string search)
{
	int i;
	int idx;
	string u = "", v = "";

	if (search.size() == 0) return search;

	buffer.push(search[0]);

	for (i = 1; i < search.size(); i++)
	{
		if (buffer.empty()) break;
		char s = buffer.top();

		if (s == search[i])
		{
			buffer.push(search[i]);
		}
		else
		{
			buffer.pop();
		}
	}

	idx = i;
	for (i = 0; i < idx; i++)
	{
		u += search[i];
	}
	for (i = idx; i < search.size(); i++)
	{
		v += search[i];
	}

	if (correct_check(u))
	{
		return u + dfs(v);
	}
	else
	{
		string res = "";
		res += "(" + dfs(v) + ")";
		for (i = 1; i < u.size() - 1; i++)
		{
			if (u[i] == '(')
			{
				res += ")";
			}
			else
			{
				res += "(";
			}
		}
		return res;
	}
}

string solution(string p) {
	string answer = "";
	answer = dfs(p);
	return answer;
}