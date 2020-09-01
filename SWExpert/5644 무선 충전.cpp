#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int dr[5] = { 0,-1,0,1,0 };
int dc[5] = { 0,0,1,0,-1 };

vector<int> move1;
vector<int> move2;

typedef struct info {
	int r1;
	int c1;
	int r2;
	int c2;
}info;

typedef struct ap_info {
	int r;
	int c;
	int coverage;
	int performance;
}ap_info;


queue<info> q;
vector<ap_info> ap_information;
vector<ap_info> cover1;
vector<ap_info> cover2;

bool sort_list(ap_info a, ap_info b)
{
	return a.performance > b.performance;
}

int main()
{
	int T;
	int m, a;
	int i, j, k;
	int temp;

	int usage1, usage2;

	int r1, c1, r2, c2;

	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		move1.clear();
		move2.clear();
		move1.push_back(0);
		move2.push_back(0);
		ap_information.clear();
		r1 = 1;
		c1 = 1;
		r2 = 10;
		c2 = 10;
		usage1 = 0;
		usage2 = 0;
		scanf("%d %d", &m, &a);
		//사용자1의 이동 정보
		for (i = 0; i < m; i++)
		{
			scanf("%d", &temp);
			move1.push_back(temp);
		}
		//사용자2의 이동 정보
		for (i = 0; i < m; i++)
		{
			scanf("%d", &temp);
			move2.push_back(temp);
		}

		//ap의 정보를 받아 저장
		for (i = 0; i < a; i++)
		{
			ap_info insert;
			scanf("%d %d %d %d", &insert.c, &insert.r, &insert.coverage, &insert.performance);
			ap_information.push_back(insert);
		}

		//움직이면서 충전 정보를 누적해서 저장
		for (i = 0; i <= m; i++)
		{
			cover1.clear();
			cover2.clear();

			//이동을 시켜줌
			r1 = r1 + dr[move1[i]];
			c1 = c1 + dc[move1[i]];
			r2 = r2 + dr[move2[i]];
			c2 = c2 + dc[move2[i]];

			//cover갱신
			for (j = 0; j < ap_information.size(); j++)
			{
				int dist1 = abs(ap_information[j].r - r1) + abs(ap_information[j].c - c1);
				int dist2 = abs(ap_information[j].r - r2) + abs(ap_information[j].c - c2);
				if (dist1 <= ap_information[j].coverage)
				{
					cover1.push_back(ap_information[j]);
				}
				if (dist2 <= ap_information[j].coverage)
				{
					cover2.push_back(ap_information[j]);
				}
			}

			sort(cover1.begin(), cover1.end(), sort_list);
			sort(cover2.begin(), cover2.end(), sort_list);

			if ((cover1.size() == 0) && (cover2.size() == 0))  continue;
			else if ((cover1.size() == 0) && (cover2.size() != 0))
			{
				usage2 += cover2[0].performance;
				continue;
			}
			else if ((cover1.size() != 0) && (cover2.size() == 0))
			{
				usage1 += cover1[0].performance;
				continue;
			}
			else
			{
				//제일 큰 퍼포먼스 부분이 같지 않다면 그냥 더해주면 됨
				if (!(cover1[0].r == cover2[0].r && cover1[0].c == cover2[0].c))
				{
					usage1 += cover1[0].performance;
					usage2 += cover2[0].performance;
				}
				else//같다면 따져 주워야 함
				{
					if ((cover1.size() == 1) && (cover2.size() == 1))
					{
						usage1 += (cover1[0].performance / 2);
						usage2 += (cover2[0].performance / 2);
					}
					else if ((cover1.size() == 1) && (cover2.size() > 1))
					{
						usage1 += cover1[0].performance;
						usage2 += cover2[1].performance;
					}
					else if ((cover1.size() > 1) && (cover2.size() == 1))
					{
						usage1 += cover1[1].performance;
						usage2 += cover2[0].performance;
					}
					else
					{
						if (cover1[1].performance > cover2[1].performance)
						{
							usage1 += cover1[1].performance;
							usage2 += cover2[0].performance;
						}
						else
						{
							usage1 += cover1[0].performance;
							usage2 += cover2[1].performance;
						}
					}
				}
			}
		}

		printf("#%d %d\n", t + 1, usage1 + usage2);

	}

	return 0;
}