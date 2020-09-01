#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct people_info {
	int r;
	int c;
	int arrive_one;
	int arrive_two;
}people_info;

typedef struct stair_info {
	int r;
	int c;
	int time;
	int storage;
}stair_info;



vector<people_info> people_list;
vector<stair_info> stair_list;
vector<int> direct;
int stair_stat[2][3];

queue<people_info> waiting_one;
queue<people_info> waiting_two;
deque<people_info> people_list_one;
deque<people_info> people_list_two;



int T;
int n;
int ans = -1;

bool sort_one(people_info a, people_info b)
{
	return a.arrive_one < b.arrive_one;
}

bool sort_two(people_info a, people_info b)
{
	return a.arrive_two < b.arrive_two;
}

bool check_stair()
{
	for (int i = 0; i < 3; i++)
	{
		if (stair_stat[0][i] != 0)
		{
			return false;
		}
		if (stair_stat[1][i] != 0)
		{
			return false;
		}
	}

	return true;
}

void down_stair()
{
	for (int i = 0; i < 3; i++)
	{
		if (stair_stat[0][i] != 0)
		{
			stair_stat[0][i] --;
		}
		if (stair_stat[1][i] != 0)
		{
			stair_stat[1][i] --;
		}

	}
}

void queue_to_stair()
{
	for (int i = 0; i < 3; i++)
	{
		if (waiting_one.empty()) break;

		if (stair_stat[0][i] == 0)
		{
			waiting_one.pop();
			stair_stat[0][i] = stair_list[0].time;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (waiting_two.empty()) break;

		if (stair_stat[1][i] == 0)
		{
			waiting_two.pop();
			stair_stat[1][i] = stair_list[1].time;
		}
	}
}

bool desig_stat_one()
{
	for (int i = 0; i < 3; i++)
	{
		if (stair_stat[0][i] == 0)
		{
			stair_stat[0][i] = stair_list[0].time;
			return true;
		}
	}
	return false;
}

bool desig_stat_two()
{
	for (int i = 0; i < 3; i++)
	{
		if (stair_stat[1][i] == 0)
		{
			stair_stat[1][i] = stair_list[1].time;
			return true;
		}
	}
	return false;
}

int simulation()
{
	int time = 0;
	int people_out = 0;
	people_list_one.clear();
	people_list_two.clear();

	//목적지마다 배정해줌
	for (int i = 0; i < people_list.size(); i++)
	{
		if (direct[i] == 0)
		{
			people_list_one.push_back(people_list[i]);
		}
		else if (direct[i] == 1)
		{
			people_list_two.push_back(people_list[i]);
		}
	}

	//도착시간이 빠른 순대로 sort
	sort(people_list_one.begin(), people_list_one.end(), sort_one);
	sort(people_list_two.begin(), people_list_two.end(), sort_two);


	while (1)
	{
		time++;
		if (check_stair() && people_list_one.empty() && people_list_two.empty() && waiting_one.empty() && waiting_two.empty()) break;
		down_stair();
		while (1)
		{
			if (people_list_one.size() == 0) break;
			//계단의 도착 상황 갱신
			if (time != people_list_one.front().arrive_one) break;

			//계단이 비어있을 떄와 안비어 있을떄를 나눠 고려
			if (!desig_stat_one())
			{
				//만약에 실패
				//큐에 넣어줌
				waiting_one.push(people_list_one.front());
			}
			people_list_one.pop_front();
		}
		while (1)
		{
			if (people_list_two.size() == 0) break;
			//계단의 도착 상황 갱신
			if (time != people_list_two.front().arrive_two) break;

			//계단이 비어있을 떄와 안비어 있을떄를 나눠 고려
			if (!desig_stat_two())
			{
				//만약에 실패
				//큐에 넣어줌
				waiting_two.push(people_list_two.front());
			}
			people_list_two.pop_front();
		}
		queue_to_stair();

	}

	return time;
}


void dfs(int num)
{
	if (num == people_list.size())
	{
		int temp_ans = simulation();
		if (ans == -1)
		{
			ans = temp_ans;
		}
		else if (ans > temp_ans)
		{
			ans = temp_ans;
		}
		return;
	}

	//0번 배정
	direct.push_back(0);
	dfs(num + 1);
	direct.pop_back();

	//1번 배정
	direct.push_back(1);
	dfs(num + 1);
	direct.pop_back();

	return;
}

int main()
{
	int temp;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		scanf("%d", &n);
		people_list.clear();
		stair_list.clear();
		direct.clear();
		memset(stair_stat, 0, sizeof(stair_stat));
		ans = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &temp);
				if (temp == 1)
				{
					people_list.push_back({ i,j,0,0 });
				}
				else if (temp != 1 && temp != 0)
				{
					stair_list.push_back({ i,j,temp,0 });
				}
			}
		}

		//도착 시간을 배정
		for (int i = 0; i < people_list.size(); i++)
		{
			people_list[i].arrive_one = abs(people_list[i].r - stair_list[0].r) + abs(people_list[i].c - stair_list[0].c);
			people_list[i].arrive_two = abs(people_list[i].r - stair_list[1].r) + abs(people_list[i].c - stair_list[1].c);
		}

		//각 사람마다 갈 계단을 배정
		dfs(0);

		printf("#%d %d\n", t + 1, ans);

	}

	return 0;
}
