#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void search(int index, int depth);

int visited[26] = { 0, };
string temp[50];
int ans = -1;
int N, K;

int main()
{
	cin >> N >> K;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> temp[i];
	}

	for (i = 0; i < N; i++)
	{
		int size = temp[i].size();
		temp[i].erase(size - 4);
		temp[i].erase(0, 4);
	}


	if (K <= 4)
	{
		ans = 0;
	}
	else
	{
		visited[0] = 1;
		visited[2] = 1;
		visited[8] = 1;
		visited[13] = 1;
		visited[19] = 1;
		search(0, 5);
	}

	cout << ans << endl;
	return 0;
}

void search(int index, int depth)
{
	int i, j;
	int count = 0;
	if (depth == K)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < temp[i].length(); j++)
			{
				if (visited[temp[i][j] - 'a'] == 0)
				{
					break;
				}
			}
			if (j == temp[i].length())
			{
				count++;
			}
		}
		if (ans < count)
		{
			ans = count;
		}
	}
	else
	{
		for (i = index; i < 26; i++)
		{
			if ((i == 0) || (i == 2) || (i == 8) || (i == 13) || (i == 19))
			{
				continue;
			}
			visited[i] = 1;
			search(i + 1, depth + 1);
			visited[i] = 0;
		}
	}
}