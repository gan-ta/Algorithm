#include <stdio.h>
int ch1[10001] = { 0, };//왼쪽 자식
int ch2[10001] = { 0, };//오른쪽 자식
int par[10001] = { 0, };//부모에 대한 정보
int count = 0;

void count_tree(int n);


int main(void)
{
	//freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int i, j;
	for (i = 1; i <= T; i++)
	{
		int V;
		int E;
		int node1, node2;
		int anc1, anc2, result = 0;
		scanf("%d %d %d %d", &V, &E, &node1, &node2);
		for (j = 1; j <= E; j++)
		{
			int p;
			int c;
			scanf("%d %d", &p, &c);
			if (ch1[p] == 0) //왼쪽 자식에다가 넣어줌 
			{
				ch1[p] = c;
			}
			else // 왼쪽 자식이 꽉 차 있다면 오른쪽 자식에다가 넣어줌 
			{
				ch2[p] = c;
			}
			par[c] = p;
		}
		anc1 = par[node1];
		anc2 = par[node2];
		while (anc1 != 0)
		{
			anc2 = par[node2];//다시 리셋
			while (anc2 != 0)
			{
				if (anc1 == anc2)//같으면 반복문 탈출
				{
					result = anc1;
					break;
				}
				else//아니면 조상을 찾아서
				{
					anc2 = par[anc2];
				}
			}
			if (anc1 == anc2)//같으면 반복문 탈출
			{
				break;
			}
			anc1 = par[anc1];
		}

		count_tree(result);
		printf("#%d %d %d\n", i, result, count);
		/*리셋의 작업*/
		for (j = 1; j <= V; j++)
		{
			ch1[j] = 0;
			ch2[j] = 0;
			par[j] = 0;
		}
		count = 0;
	}
	return 0;
}

void count_tree(int n) // 서브트리의 노드의 개수를 세줌
{
	if (n <= 0)
	{
		return;
	}
	else
	{
		count++;
		count_tree(ch1[n]);
		count_tree(ch2[n]);
	}
}