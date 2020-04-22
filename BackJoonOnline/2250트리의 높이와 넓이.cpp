#include <iostream>
#include <queue>
using namespace std;

int leftc[10001];
int rightc[10001];
int row[10001];
int check[10001] = { 0, };
int depth[10001] = { 0, };
int width[10001] = { 0, };
queue<int> q;

int rcnt = 1;

void inorder_search(int node);
void bfs_depth_find(int node);

int main()
{
	int N;
	scanf("%d", &N);
	int i, j;
	int index;
	int root;
	for (i = 0; i < N; i++)
	{
		cin >> index;
		cin >> leftc[index];
		cin >> rightc[index];
	}

	
	for (i = 1; i <= N; i++)
	{
		if (leftc[i] != -1)
		{
			check[leftc[i]] = 1;
		}
		if (rightc[i] != -1)
		{
			check[rightc[i]] = 1;
		}
	}
	for (i = 1; i <= N; i++)
	{
		if (check[i] == 0)
		{
			root = i;
			break;
		}
	}
	
	inorder_search(root);
	
	bfs_depth_find(root);

	int maxd = depth[root];

	for (i = 1; i <= N; i++)
	{
		if (maxd < depth[i])
		{
			maxd = depth[i];
		}
	}

	
	width[1] = 1;
	for (i = 2; i <= maxd; i++)
	{
		int max = 0, min = N + 1;
		
		for (j = 1; j <= N; j++)
		{
			if (depth[j] == i)
			{
				if (max < row[j])
				{
					max = row[j];
				}
				if (min > row[j])
				{
					min = row[j];
				}
			}
		}
		width[i] = max - min + 1;
	}

	int w = width[1], level = 1;
	for (i = 2; i <= maxd; i++)
	{
		if (w < width[i])
		{
			w = width[i];
			level = i;
		}
	}

	cout << level << " " << w << endl;

	return 0;
}

void inorder_search(int node)
{
	if (node != -1)
	{
		inorder_search(leftc[node]);
		row[node] = rcnt++;
		inorder_search(rightc[node]);
	}
}

void bfs_depth_find(int node)
{
	depth[node] = 1;
	q.push(node);
	while (!q.empty())
	{
		int temp;
		temp = q.front();
		q.pop();
		if (leftc[temp] != -1)
		{
			depth[leftc[temp]] = depth[temp] + 1;
			q.push(leftc[temp]);
		}

		if (rightc[temp] != -1)
		{
			depth[rightc[temp]] = depth[temp] + 1;
			q.push(rightc[temp]);
		}
	}
}