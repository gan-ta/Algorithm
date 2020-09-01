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
	int life_time;//생명주기
	int remain_time;//남아있는 생명주기
	char status;//현재 상태 -> 비할성:0/ 활성:1
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
				//초기 상태를 설정
				if (temp != 0)
				{
					visited[300 + i][300 + j] = -1;
					q.push(info({ 300 + i,300 + j,temp,temp,0,0 }));
				}
			}
		}


		//k번의 싸이클을 돌음
		for (i = 0; i < k; i++)
		{
			//큐의 사이즈 만큼 한번을 돌음
			int size = q.size();
			st.clear();

			for (j = 0; j < size; j++)
			{
				info search = q.front();
				q.pop();

				search.remain_time--;


				//활성 상태 퍼트리기
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
					//비활성화이면 활성화로 만들고 remain_time 재설정
					if (search.status == 0)
					{
						search.remain_time = search.life_time;
						search.status = 1;
						q.push(search);
					}
				}

			}

			//퍼트린 결과를 반영하여 큐에 저장
			arrange();

		}

		printf("#%d %d\n", c + 1, q.size());

	}

	return 0;
}