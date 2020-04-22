#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char country[4][12];
double map[4][4][3];

int score[4][4][3] = {0,};
double percentage[4] = {0,};

int check(char* str)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (strcmp(str, country[i]) == 0)
		{
			return i;
		}
	}
}

void calculate()
{
	int i,j,k;
	int s[4] = {0,};
	int a = 0;
	int b = 0;
	int c = 0;
	int standard;
	double p = 1;
	double temp;

	//승점 계산
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 2; k++)
			{
				if (k == 0)
				{
					s[i] += score[i][j][k] * 3;
				}
				else if (k == 1)
				{
					s[i] += score[i][j][k];
				}
			}
		}
	}

	//score가 될 확률을 설정
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 4; j++)
		{
			for (k = 0; k < 2; k++)
			{
				if (score[i][j][k] == 1)
				{
					p = p * map[i][j][k];
				}
			}
		}
	}

	double temp_p = p;

	//이길 확률 구하기
	for (i = 0; i < 4; i++)
	{
		standard = s[i];
		p = temp_p;
		temp = 0;
		for (j = 0; j < 4; j++)
		{
			if (i != j)
			{
				if (standard > s[j])
				{
					a++;
				}
				else if (standard == s[j])
				{
					b++;
				}
				else
				{
					c++;
				}
			}
		}

		//무조건 올라가는 경우
		if (a >= 2)
		{
			percentage[i] += p;
		}
		else if (c >= 2)//무조건 떨어지는 경우
		{
			percentage[i] += 0;
		}
		else if (b == 1)
		{
			temp = 1 / 2;
			percentage[i] += (p * temp);
		}
		else if (b == 2)
		{
			temp = 1 / 3;
			percentage[i] += (p * temp);
		}
		else if (b == 3)
		{
			temp = 1 / 4;
			percentage[i] += (p * temp);
		}

		a = 0;
		b = 0; 
		c = 0;
	}

	for (i = 0; i < 4; i++)
	{
		printf("%lf ", percentage[i]);
	}
	printf("\n");

}

void dfs(int depth)
{
	if (depth == 7)
	{
		calculate();
		return;
	}
	int team1;
	int team2;

	if (depth >= 1 && depth <= 3)
	{
		team1 = 0;
		team2 = depth;
	}
	else if (depth >= 4 && depth <= 5)
	{
		team1 = 1;
		team2 = depth - 2;
	}
	else if (depth == 6)
	{
		team1 = 2;
		team2 = 3;
	}
	
	//승리하였을시
	score[team1][team2][0]++;
	score[team2][team1][2]++;
	dfs(depth + 1);
	score[team2][team1][2]--;
	score[team1][team2][0]--;

	//비겼을시
	score[team1][team2][1]++;
	score[team2][team1][1]++;
	dfs(depth + 1);
	score[team2][team1][1]--;
	score[team1][team2][1]--;

	//졌을시
	score[team1][team2][2]++;
	score[team2][team1][0]++;
	dfs(depth + 1);
	score[team2][team1][0]--;
	score[team1][team2][2]--;
}

int main()
{
	int i;
	int idx = 0;
	int cnt = 0;
	int cnt2 = 0;
	int len = 0;
	double w, d, l;
	for (i = 0; i < 4; i++)
	{
		scanf("%s", country[i]);
	}

	for (i = 0; i < 6; i++)
	{
		char temp1[12];
		char temp2[12];
		int num1;
		int num2;
		scanf("%s", temp1);
		scanf("%s", temp2);
		num1 = check(temp1);
		num2 = check(temp2);
		scanf("%lf %lf %lf", &w,&d,&l);
		map[num1][num2][0] = w;
		map[num1][num2][1] = d;
		map[num1][num2][2] = l;
		map[num2][num1][0] = l;
		map[num2][num1][1] = d;
		map[num2][num1][2] = w;
	}
	
	dfs(1);
	
	for (i = 0; i < 4; i++)
	{
		printf("%.10f\n", percentage[i]);
	}

	return 0;
}