#include <cstdio>
#include <vector>
using namespace std;

vector<int> curve;


int visited[102][102] = { 0, };

int n, x, y, d, g ;

void curve_calculate(int depth)
{
	int i;
	vector<int> temp;
	
	if(depth == g) return;

	for (i = curve.size()-1; i >= 0; i--)
	{
		temp.push_back((curve[i] + 1) % 4);
	}

	for (i = 0; i < temp.size(); i++)
	{
		curve.push_back(temp[i]);
	}

	curve_calculate(depth + 1);
}

void curve_visit()
{
	int i;
	int tx, ty;
	tx = x;
	ty = y;
	visited[ty][tx] = 1;
	for (i = 0; i < curve.size(); i++)
	{
		if(curve[i] == 0)
		{
			tx = tx+1;
			ty = ty;
			if (visited[ty][tx] == 0)
			{
				visited[ty][tx] = 1;
			}

		}
		else if(curve[i] == 1)
		{
			tx = tx;
			ty = ty-1;
			if (visited[ty][tx] == 0)
			{
				visited[ty][tx] = 1;
			}
		}
		else if(curve[i] == 2)
		{
			tx = tx-1;
			ty = ty;
			if (visited[ty][tx] == 0)
			{
				visited[ty][tx] = 1;
			}
		
		}
		else if(curve[i] == 3)
		{
			tx = tx;
			ty = ty+1;
			if (visited[ty][tx] == 0)
			{
				visited[ty][tx] = 1;
			}
		}
		
	}
}

int main()
{
	int i, j;
	int res = 0;
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		curve.push_back(d);
		curve_calculate(0);
		curve_visit();
		curve.clear();
	}


	for (i = 0; i < 100; i++) 
	{
		for (j = 0; j < 100; j++)
		{
			if (visited[i][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j] == 1 && visited[i + 1][j + 1] == 1) res++;
		}
	}

	printf("%d\n", res);
	return 0;
}