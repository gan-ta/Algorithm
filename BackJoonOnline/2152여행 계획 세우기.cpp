#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <cstring>
using namespace std;


vector<int> forword[10001];
vector<int> re[10001];
stack<int> vertex_stack;
int visited[10001] = { 0, };


vector<int> scc[10001];
int scc_number[10001];
vector<int> scc_graph[10001];

void dfs_forword(int start);
void dfs_re(int start, int scc_num);
int search(int start);

int N, M, S, T;


int dp[10001] = { 0, };

int main()
{
	int i, j;
	int start, end;
	int scc_num = 1;
	int temp_vertex;
	int max;
	cin >> N >> M >> S >> T;
	for (i = 0; i < M; i++)
	{
		cin >> start;
		cin >> end;
		forword[start].push_back(end);
		re[end].push_back(start);
	}

	
	for (i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			dfs_forword(i);
		}
	}

	memset(visited, 0, sizeof(visited));

	
	while (!vertex_stack.empty())
	{
		temp_vertex = vertex_stack.top();
		vertex_stack.pop();
		if (visited[temp_vertex] == 0)
		{
			dfs_re(temp_vertex, scc_num);
			scc_num++;
		}
	}

	
	for (i = 1; i < scc_num; i++)
	{
		for (j = 0; j < scc[i].size(); j++)
		{
			scc_number[scc[i][j]] = i;
		}
	}


	
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < forword[i].size(); j++)
		{
			if (scc_number[i] != scc_number[forword[i][j]])
			{
				scc_graph[scc_number[i]].push_back(scc_number[forword[i][j]]);
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	search(scc_number[S]);

	if (visited[scc_number[T]] == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		cout << dp[scc_number[S]] << endl;
	}



	return 0;
}

void dfs_forword(int start)
{
	int i;
	visited[start] = 1;
	for (i = 0; i < forword[start].size(); i++)
	{
		if (visited[forword[start][i]] == 0)
		{
			dfs_forword(forword[start][i]);
		}
	}
	vertex_stack.push(start);
}

void dfs_re(int start, int scc_num)
{
	int i;
	visited[start] = 1;
	scc[scc_num].push_back(start);
	for (i = 0; i < re[start].size(); i++)
	{
		if (visited[re[start][i]] == 0)
		{
			dfs_re(re[start][i], scc_num);
		}
	}
}

int search(int start)
{
	int i;
	visited[start] = 1;
	if (start == scc_number[T])
	{
		if (dp[start] == 0)
		{
			dp[start] += scc[start].size();
		}
	}
	else
	{
		if (dp[start] == 0)
		{
			dp[start] = -10002;

			for (i = 0; i < scc_graph[start].size(); i++)
			{
				int num = scc[start].size();
				int s = search(scc_graph[start][i]);
				if (dp[start] < num + s)
				{
					dp[start] = num + s;
				}
			}
		}
	}

	return dp[start];
}