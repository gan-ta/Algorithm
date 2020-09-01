#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char visited[650][650] = { 0, };
int t;
int n, m, k;

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

typedef struct info {
	int r;
	int c;
	int life_time;//�����ֱ�
	int remain_time;//�����ִ� �����ֱ�
	char status;//���� ���� -> ���Ҽ�:0/ Ȱ��:1
	char check;
}info;

typedef struct renew {
	int r;
	int c;
	int life;
}renew;

queue<info> q;
vector<renew> st;

bool asc(renew a, renew b)
{
	return a.life > b.life;
}

void arrange()
{
	int i;

	sort(st.begin(), st.end(), asc);

	for (i = 0; i < st.size(); i++)
	{
		renew search = st[i];
		if (visited[search.r][search.c] != -1)
		{
			visited[search.r][search.c] = -1;
			q.push(info({ search.r,search.c,search.life,search.life,0,0 }));
		}
	}
}


int main()
{
	int i, j, l;
	int temp;
	int nr, nc;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);

	for (int c = 0; c < t; c++)
	{
		scanf("%d", &n);
		scanf("%d", &m);
		scanf("%d", &k);

		while (!q.empty())
		{
			q.pop();
		}

		memset(visited, 0, sizeof(visited));

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &temp);
				//�ʱ� ���¸� ����
				if (temp != 0)
				{
					visited[300 + i][300 + j] = -1;
					q.push(info({ 300 + i,300 + j,temp,temp,0,0 }));
				}
			}
		}


		//k���� ����Ŭ�� ����
		for (i = 0; i < k; i++)
		{
			//ť�� ������ ��ŭ �ѹ��� ����
			int size = q.size();
			st.clear();

			for (j = 0; j < size; j++)
			{
				info search = q.front();
				q.pop();

				search.remain_time--;


				//Ȱ�� ���� ��Ʈ����
				if (search.status == 1 && search.check != 1)
				{
					for (l = 0; l < 4; l++)
					{
						nr = search.r + dr[l];
						nc = search.c + dc[l];

						if (visited[nr][nc] != -1)
						{
							st.push_back(renew({ nr,nc,search.life_time }));
						}
					}
					search.check = 1;
				}


				if (search.remain_time != 0)
				{
					q.push(search);
				}
				else if (search.remain_time == 0)
				{
					//��Ȱ��ȭ�̸� Ȱ��ȭ�� ����� remain_time �缳��
					if (search.status == 0)
					{
						search.remain_time = search.life_time;
						search.status = 1;
						q.push(search);
					}
				}

			}

			//��Ʈ�� ����� �ݿ��Ͽ� ť�� ����
			arrange();

		}

		printf("#%d %d\n", c + 1, q.size());

	}

	return 0;
}