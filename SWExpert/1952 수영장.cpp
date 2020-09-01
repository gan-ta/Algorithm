#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

//1일, 1달, 3달, 1년
int price1, price2, price3, price4;
int usage[12];
int ans = -1;

void dfs(int depth, int result)
{
	if (depth >= 12)
	{
		if (ans == -1 || ans > result) ans = result;
		return;
	}

	//1일권을 사용시
	dfs(depth + 1, result + usage[depth] * price1);
	//1달권을 사용시
	dfs(depth + 1, result + price2);
	//3달권을 사용시
	dfs(depth + 3, result + price3);
	//1년권을 사용시
	dfs(depth + 12, result + price4);

}


int main()
{

	int T;
	int i, j;
	int temp;
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		scanf("%d %d %d %d", &price1, &price2, &price3, &price4);
		memset(usage, 0, sizeof(usage));
		ans = -1;
		for (i = 0; i < 12; i++)
		{
			scanf("%d", &temp);
			usage[i] = temp;
		}

		dfs(0, 0);
		printf("#%d %d\n", t + 1, ans);

	}

	return 0;
}