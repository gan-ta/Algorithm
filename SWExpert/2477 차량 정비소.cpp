#include <cstdio>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

int N, M, K, A, B;

typedef struct info {
	int num;//������ȣ
	int t;//���½ð�
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
	//first waiting ����
	for (int i = 0; i < recept_stat.size(); i++)
	{
		if (first_waiting.empty()) break;
		//��������� ť���� �ϳ� �� ����
		if (recept_stat[i].num == 0)
		{
			info insert = first_waiting.front();
			first_waiting.pop();
			insert.recept_num = i;
			insert.remain_time = recept[i];
			recept_stat[i] = insert;
		}
	}

	//second waiting ����
	for (int i = 0; i < repair_stat.size(); i++)
	{
		if (second_waiting.empty()) break;
		//��������� ť���� �ϳ� �� ����
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
	//recept_stat������ �۾� ����
	//�۾��� �������� second ť�� ����
	for (int i = 0; i < recept_stat.size(); i++)
	{
		//����� ������ �۾� ó��
		if (recept_stat[i].num != 0)
		{
			recept_stat[i].remain_time--;

			//�۾��� �Ϸᰡ �Ǿ����� secondť��
			if (recept_stat[i].remain_time == 0)
			{
				second_waiting.push(recept_stat[i]);
				recept_stat[i] = { 0,0,0,0,0 };
			}
		}
	}

	//repair_stat������ �۾� ����
	for (int i = 0; i < repair_stat.size(); i++)
	{
		//����� ������ �۾� ó��
		if (repair_stat[i].num != 0)
		{
			repair_stat[i].remain_time--;

			//�۾��� �Ϸᰡ �Ǿ����� �Ϸ� ���¿� �־��ֱ�
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

			//people ���� wating���� ���� �۾�
			check_people(time);
			//��ġ�۾�
			desig_waiting();
			//recept�� repair�۾�
			work();
			time++;
		}

		//�� ����
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