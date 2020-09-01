#include <cstdio>
#include <vector>
using namespace std;


int max_num = -1000000001;
int min_num = 1000000001;
int num;
vector<int> num_arr;
vector<int> operator_num;

void dfs(int num_idx, int res) {

	if (num_idx == num) {
		if (res > max_num) {
			max_num = res;
		}

		if (res < min_num) {
			min_num = res;
		}

		return;
	}
	
	//µ¡¼ÀÀÌ ³²¾Æ ÀÖÀ» °æ¿ì
	if (operator_num[0] != 0) {
		operator_num[0]--;
		dfs(num_idx + 1, res + num_arr[num_idx]);
		operator_num[0]++;
	}
	
	//¹ë¼ÀÀÌ ³²¾Æ ÀÖÀ» °æ¿ì
	if (operator_num[1] != 0) {
		operator_num[1]--;
		dfs(num_idx + 1, res - num_arr[num_idx]);
		operator_num[1]++;
	}

	//°ö¼ÀÀÌ ³²¾Æ ÀÖÀ» °æ¿ì
	if (operator_num[2] != 0) {
		operator_num[2]--;
		dfs(num_idx + 1, res * num_arr[num_idx]);
		operator_num[2]++;
	}

	//³ª´°¼ÀÀÌ ³²¾Æ ÀÖÀ» °æ¿ì
	if (operator_num[3] != 0) {
		operator_num[3]--;
		dfs(num_idx + 1, res / num_arr[num_idx]);
		operator_num[3]++;
	}


}

int main()
{
	int temp;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		num_arr.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &temp);
		operator_num.push_back(temp);
	}


	dfs(1,num_arr[0]);

	printf("%d\n", max_num);
	printf("%d\n", min_num);


	return 0;
}