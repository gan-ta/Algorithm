#include <iostream>
using namespace std;

void dfs(int start, int depth);

#define MAX_SIZE 13
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;

int main()
{
	int i;

	cin >> k;
	while (k != 0)
	{
		for (i = 0; i < k; i++)
		{
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << '\n';
		cin >> k;
	}


	return 0;
}

void dfs(int start, int depth)
{
	int i;
	if (depth == 6)
	{
		for (i = 0; i < 6; i++)
		{
			cout << combi[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (i = start; i < k; i++)
	{
		combi[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}