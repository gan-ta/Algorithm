#include<cstdio>
using namespace std;

int num_arr[1001];
int dp[1001]; 

int main()
{
	int a;
	int res = -1;
	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%d", &num_arr[i]);
	}


	//���ڸ� ����
	for (int i = 0; i < a; i++) {
		int location = -1;

		//�̹� ������ ��ġ���� ����
		for (int j = 0; j < i; j++) {
			if (num_arr[j] < num_arr[i]) {
				if (location < dp[j]) {
					location = dp[j];
				}
			}
		}
		//dp���� ����(��ġ�� ����)
		dp[i] = location + 1;

		if (res < dp[i]) {
			res = dp[i];
		}

	}

	printf("%d\n", res+1);

	return 0;
}