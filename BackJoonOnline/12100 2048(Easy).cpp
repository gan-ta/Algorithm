#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n ;
int res = -1;

vector<vector<int>> map;

void dfs(int depth, int direct,vector<vector<int>> temp_map)
{
	int i, j,k;
	int max_num = -1;
	int temp;
	int point;
	if (depth == 5)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (max_num < temp_map[i][j])
				{
					max_num = temp_map[i][j];
				}
			}
		}

		if (res < max_num)
		{
			res = max_num;
		}
		return;
	}

	if (direct == 0)
	{
		for (j = 0; j < n; j++)
		{
			point = 0;
			for (i = 1; i < n; i++)
			{
				if (temp_map[i][j] != 0)
				{
					if (temp_map[i][j] == temp_map[point][j])
					{
						temp_map[point][j] = temp_map[point][j] * 2;
						temp_map[i][j] = 0;
						point = point + 1;
					}
					else
					{
						if (temp_map[point][j] != 0)
						{
							point = point + 1;
							temp_map[point][j] = temp_map[i][j];
						}
						else
						{
							temp_map[point][j] = temp_map[i][j];
						}

						if (point != i)
						{
							temp_map[i][j] = 0;
						}
					}
				}
			}
		}
	}
	else if (direct == 1)
	{
		for (j = 0; j < n; j++)
		{
			point = n - 1;
			for (i = n - 2; i >= 0; i--)
			{
				if (temp_map[i][j] != 0)
				{
					if (temp_map[i][j] == temp_map[point][j])
					{
						temp_map[point][j] = temp_map[point][j] * 2;
						temp_map[i][j] = 0;
						point = point - 1;

					}
					else
					{
						if (temp_map[point][j] != 0)
						{
							point = point - 1;
							temp_map[point][j] = temp_map[i][j];
						}
						else
						{
							temp_map[point][j] = temp_map[i][j];
						}

						if (point != i)
						{
							temp_map[i][j] = 0;
						}
					}
				}
			}
		}
	}
	else if (direct == 2)
	{
		for (i = 0; i < n; i++)
		{
			point = 0;
			for (j = 1; j < n; j++)
			{
				if (temp_map[i][j] != 0)
				{
					if (temp_map[i][j] == temp_map[i][point])
					{
						temp_map[i][point] = temp_map[i][point] * 2;
						temp_map[i][j] = 0;
						point = point + 1;

					}
					else
					{
						if (temp_map[i][point] != 0)
						{
							point = point + 1;
							temp_map[i][point] = temp_map[i][j];
						}
						else
						{
							temp_map[i][point] = temp_map[i][j];
						}

						if (point != j)
						{
							temp_map[i][j] = 0;
						}
					}
				}
			}
		}
	}
	else if (direct == 3)
	{
		for (i = 0; i < n; i++)
		{
			point = n-1;
			for (j = n-2; j >= 0; j--)
			{
				if (temp_map[i][j] != 0)
				{
					if (temp_map[i][j] == temp_map[i][point])
					{
						temp_map[i][point] = temp_map[i][point] * 2;
						temp_map[i][j] = 0;
						point = point - 1;

					}
					else
					{
						if (temp_map[i][point] != 0)
						{
							point = point - 1;
							temp_map[i][point] = temp_map[i][j];				
						}
						else
						{
							temp_map[i][point] = temp_map[i][j];
						}

						if (point != j)
						{
							temp_map[i][j] = 0;
						}
					}
				}
			}
		}
	}

	for (i = 0; i < 4; i++)
	{
		dfs(depth + 1, i, temp_map);
	}
	return;
	
}

int main()
{

	int i, j;
	int num;
	vector<int> temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &num);
			temp.push_back(num);
		}
		map.push_back(temp);
		temp.clear();
	}

	for (i = 0; i < 4; i++)
	{
		dfs(0, i, map);
	}

	printf("%d\n", res);
	return 0;
}