#include<cstdio>
using namespace std;

int num_arr[1001];
int dp[1001]; //�պ��� �������� ���� ���� �ִ밪���� �����Ͽ� ����

int main()
{
	int a;
	int res = -1;
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%d", &num_arr[i]);
	}

	for (int i = 0; i < a; i++) {
		int max_amount = 0;

		for (int j = 0; j < i; j++) {
			if (num_arr[j] < num_arr[i]) {
				if (max_amount < dp[j]) {
					max_amount = dp[j];
				}
			}
		}

		//���������� �����ϴ� �ε������� ������ �ִ� �ִ��� �� ����
		dp[i] = max_amount + num_arr[i];

		if (res < dp[i]) res = dp[i];
	}

	printf("%d\n", res);

	return 0;
}