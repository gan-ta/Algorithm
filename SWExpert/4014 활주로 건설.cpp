#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int map[21][21];
int visited[21];
int T;
int n;
int x;
vector<int> search;

bool check_arr()
{

	//���������� �� ��
	int arrange;
	int check_num;

	arrange = 1;
	check_num = search[0];

	for (int i = 1; i < search.size(); i++)
	{
		if (check_num == search[i])
		{
			arrange += 1;
			continue;
		}
		else if (check_num + 1 == search[i])
		{
			if (arrange < x) return false;
			else
			{
				if (visited[i] == 1) return false; //�̹� Ȱ�ַΰ� ������ �������� ����
				for (int j = i - 1; j >= i - x; j--)
				{
					if (visited[j] == 1) return false;
					visited[j] = 1;
				}
				check_num = search[i];
				arrange = 1;
			}
		}
		else if (search[i] > check_num + 1)
		{
			return false;
		}
		else if (check_num > search[i])
		{
			check_num = search[i];
			arrange = 1;
		}
	}

	arrange = 1;
	check_num = search[search.size() - 1];

	for (int i = search.size() - 2; i >= 0; i--)
	{
		if (check_num == search[i])
		{
			arrange += 1;
			continue;
		}
		else if (check_num + 1 == search[i])
		{
			if (arrange < x) return false;
			else
			{
				if (visited[i] == 1) return false; //�̹� Ȱ�ַΰ� ������ �������� ����
				for (int j = i + 1; j <= i + x; j++)
				{
					if (visited[j] == 1) return false;
					visited[j] = 1;
				}
				check_num = search[i];
				arrange = 1;
			}
		}
		else if (search[i] > check_num + 1)
		{
			return false;
		}
		else if (check_num > search[i])
		{
			check_num = search[i];
			arrange = 1;
		}
	}

	return true;
}

int main()
{
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int ans = 0;
		scanf("%d %d", &n, &x);
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		//�� �ٸ��� search�� ��
		//������ ����
		for (int i = 0; i < n; i++)
		{
			search.clear();
			memset(visited, 0, sizeof(visited));
			for (int j = 0; j < n; j++)
			{
				search.push_back(map[j][i]);
			}
			if (check_arr())
			{
				ans++;
			}
		}
		//�ึ�� ����
		for (int i = 0; i < n; i++)
		{
			search.clear();
			memset(visited, 0, sizeof(visited));
			for (int j = 0; j < n; j++)
			{
				search.push_back(map[i][j]);
			}
			if (check_arr())
			{
				ans++;
			}
		}

		printf("#%d %d\n", t + 1, ans);

	}
	return 0;
}