#include <stdio.h>
int ch1[10001] = { 0, };//���� �ڽ�
int ch2[10001] = { 0, };//������ �ڽ�
int par[10001] = { 0, };//�θ� ���� ����
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
			if (ch1[p] == 0) //���� �ڽĿ��ٰ� �־��� 
			{
				ch1[p] = c;
			}
			else // ���� �ڽ��� �� �� �ִٸ� ������ �ڽĿ��ٰ� �־��� 
			{
				ch2[p] = c;
			}
			par[c] = p;
		}
		anc1 = par[node1];
		anc2 = par[node2];
		while (anc1 != 0)
		{
			anc2 = par[node2];//�ٽ� ����
			while (anc2 != 0)
			{
				if (anc1 == anc2)//������ �ݺ��� Ż��
				{
					result = anc1;
					break;
				}
				else//�ƴϸ� ������ ã�Ƽ�
				{
					anc2 = par[anc2];
				}
			}
			if (anc1 == anc2)//������ �ݺ��� Ż��
			{
				break;
			}
			anc1 = par[anc1];
		}

		count_tree(result);
		printf("#%d %d %d\n", i, result, count);
		/*������ �۾�*/
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

void count_tree(int n) // ����Ʈ���� ����� ������ ����
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