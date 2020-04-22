#include <iostream>
#include <cstring>
using namespace std;

int w[1001][1001];//연결 정보 저장
int nearest[1001];//노드가 연결되어 있는 vertex정보
int length[1001];//몾겆ㄱ지에서 노드까지의 길이의 최소값
int N, M;
int vnear;
int minimum;


int main()
{
	int i, j;
	cin >> N >> M;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			w[i][j] = 100;
		}
	}

	for (i = 0; i < M; i++)
	{
		int start;
		int end;
		int weight;
		cin >> start >> end >> weight;
		w[start][end] = weight;
		w[end][start] = weight;
	}

	for (i = 2; i <= N; i++)
	{
		nearest[i] = 1;
		length[i] = w[1][i];
	}

	for (i = 2; i <= N; i++)
	{
		minimum = 100;

		for (j = 2; j <= N; j++)
		{
			if ((0 <= length[j]) && (length[j] < minimum))
			{
				minimum = length[j];
				vnear = j;
			}
		}

		for (j = 2; j <= N; j++)
		{
			if ((length[vnear] + w[vnear][j]) < length[j])
			{
				length[j] = length[vnear] + w[vnear][j];
				nearest[j] = vnear;
			}
		}
		length[vnear] = -1;
	}

	cout << N - 1 << endl;
	for (i = 2; i <= N; i++)
	{
		cout << i << " " << nearest[i] << endl;
	}

	return 0;
}
