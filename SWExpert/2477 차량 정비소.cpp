#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N, M, K, A, B;

typedef struct info {
	int num;//접수번호
	int t;//오는시간
	int recept_num;
	int repair_num;
	int remain_time;
}info;

vector<int> recept;
vector<int> repair;
vector<info> recept_stat;
vector<info> repair_stat;
vector<info> result;

deque<info> people;
queue<info> first_waiting;
queue<info> second_waiting;

bool stat_check()
{
	for (int i = 0; i < recept_stat.size(); i++)
	{
		if (recept_stat[i].num != 0) return false;
	}
	for (int i = 0; i < repair_stat.size(); i++)
	{
		if (repair_stat[i].num != 0) return false;
	}
	return true;
}

bool check_info(info a, info b)
{
	if (a.t != b.t)
	{
		return a.t < b.t;
	}
	else
	{
		return a.num < b.num;
	}
}


void check_people(int time)
{
	while (people.size() != 0)
	{
		if (time != people.front().t) break;

		info insert = people.front();

		first_waiting.push(insert);

		people.pop_front();

	}
}

void desig_waiting()
{
	//first waiting 배정
	for (int i = 0; i < recept_stat.size(); i++)
	{
		if (first_waiting.empty()) break;
		//비어있으면 큐에서 하나 뺴 지정
		if (recept_stat[i].num == 0)
		{
			info insert = first_waiting.front();
			first_waiting.pop();
			insert.recept_num = i;
			insert.remain_time = recept[i];
			recept_stat[i] = insert;
		}
	}

	//second waiting 배정
	for (int i = 0; i < repair_stat.size(); i++)
	{
		if (second_waiting.empty()) break;
		//비어있으면 큐에서 하나 뺴 지정
		if (repair_stat[i].num == 0)
		{
			info insert = second_waiting.front();
			second_waiting.pop();
			insert.repair_num = i;
			insert.remain_time = repair[i];
			repair_stat[i] = insert;
		}
	}
}

void work()
{
	//recept_stat에서의 작업 수행
	//작업이 끝났으면 second 큐로 보냄
	for (int i = 0; i < recept_stat.size(); i++)
	{
		//사람이 있으면 작업 처리
		if (recept_stat[i].num != 0)
		{
			recept_stat[i].remain_time--;

			//작업이 완료가 되었으면 second큐로
			if (recept_stat[i].remain_time == 0)
			{
				second_waiting.push(recept_stat[i]);
				recept_stat[i] = { 0,0,0,0,0 };
			}
		}
	}

	//repair_stat에서의 작업 수행
	for (int i = 0; i < repair_stat.size(); i++)
	{
		//사람이 있으면 작업 처리
		if (repair_stat[i].num != 0)
		{
			repair_stat[i].remain_time--;

			//작업이 완료가 되었으면 완료 상태에 넣어주기
			if (repair_stat[i].remain_time == 0)
			{
				result.push_back(repair_stat[i]);
				repair_stat[i] = { 0,0,0,0,0 };
			}
		}
	}

}

int main()
{
	int T;
	int ans = 0;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		recept.clear();
		repair.clear();
		recept_stat.clear();
		repair_stat.clear();
		result.clear();
		ans = 0;
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);

		for (int i = 0; i < N; i++)
		{
			int temp;
			scanf("%d", &temp);
			recept.push_back(temp);
			recept_stat.push_back({ 0,0,0,0,0 });
		}

		for (int i = 0; i < M; i++)
		{
			int temp;
			scanf("%d", &temp);
			repair.push_back(temp);
			repair_stat.push_back({ 0,0,0,0,0 });
		}

		for (int i = 1; i <= K; i++)
		{
			int temp;
			scanf("%d", &temp);
			people.push_back({ i,temp,0,0,0 });
		}

		sort(people.begin(), people.end(), check_info);

		int time = 0;


		while (1)
		{
			if (people.size() == 0 && first_waiting.size() == 0 && second_waiting.size() == 0 && stat_check()) break;

			//people 에서 wating으로 가는 작업
			check_people(time);
			//배치작업
			desig_waiting();
			//recept과 repair작업
			work();
			time++;
		}

		//답 도출
		for (int i = 0; i < result.size(); i++)
		{
			if ((result[i].recept_num == (A - 1)) && (result[i].repair_num == (B - 1)))
			{
				ans += result[i].num;
			}
		}
		if (ans == 0) ans = -1;

		printf("#%d %d\n", t + 1, ans);

	}
	return 0;
}