#include <cstdio>
#include <vector>
#include <utility>
using namespace std;


int map[31][12];//ù���� ���ڴ� ���μ��� ����, �ι�°�� ����°�� �̾��� ��
int put_check[12];

int n = 0, m = 0, h = 0;


int res = -1;

int ladder_cnt;

bool flag;




void dfs(int y, int cnt) {

	if (flag)
		return;

	if (ladder_cnt == cnt) {
		bool possible = true;

		for (int i = 1; i <= n; i++) {
			int row = i;
			for(int j = 0 ; j < )
		}
	}


}

int main()
{
	int temp1, temp2;
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &temp1, &temp2);
		map[temp1-1][temp2] = 1;
	}

	for (int i = 0; i < 3; i++) {
		ladder_cnt = i;

		dfs(0, 0);

		if (flag) {
			printf("%d\n", ladder_cnt);
			return 0;
		}
	}

	printf("-1\n");

	return 0;
}