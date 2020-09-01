#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[101][101];

typedef struct info {
	int num;
	int cnt;
}info;

int row_cnt, col_cnt;
int num_cnt[101];
int r, c, k;

bool compare(info a, info b) {
	if (a.cnt < b.cnt) {
		return true;
	}
	else if (a.cnt > b.cnt) {
		return false;
	}
	else {
		if (a.num < b.num) {
			return true;
		}
		else {
			return false;
		}
	}
}

vector<info> num_count() {
	info insert;
	vector<info> res;
	for (int j = 1; j < 101; j++) {
		if (num_cnt[j] != 0) {
			insert.num = j;
			insert.cnt = num_cnt[j];
			res.push_back(insert);
		}
	}

	return res;
}

void row_calc() {
	//행에 대하여 정렬
	vector<info> renewal;
	vector<info>::iterator iter;
	vector<int> renewal2;
	int max_len = 0;

	for (int i = 0; i < row_cnt; i++) {
		memset(num_cnt, 0, sizeof(num_cnt));
		renewal.clear();
		renewal2.clear();
		for (int j = 0; j < col_cnt; j++) {
			num_cnt[arr[i][j]]++;
		}

		renewal = num_count();

		sort(renewal.begin(), renewal.end(), compare);

		for (iter = renewal.begin(); iter != renewal.end(); iter++) {
			renewal2.push_back(iter->num);
			renewal2.push_back(iter->cnt);
		}

		for (int j = 0; j < col_cnt; j++) {
			arr[i][j] = 0;
		}


		int renewal2_size = renewal2.size();
		for (int j = 0; j < renewal2_size; j++) {
			if (j == 100) break;
			arr[i][j] = renewal2[j];
		}

		if (max_len < renewal2.size()) max_len = renewal2_size;
	}

	if (max_len > 100) max_len = 100;
	col_cnt = max_len;


}

void col_calc() {
	//열에 대하여 정렬
	vector<info> renewal;
	vector<info>::iterator iter;
	vector<int> renewal2;
	info insert;
	int max_len = 0;

	for (int i = 0; i < col_cnt; i++) {
		memset(num_cnt, 0, sizeof(num_cnt));
		renewal.clear();
		renewal2.clear();
		for (int j = 0; j < row_cnt; j++) {
			num_cnt[arr[j][i]]++;
		}


		renewal = num_count();

		sort(renewal.begin(), renewal.end(), compare);

		for (iter = renewal.begin(); iter != renewal.end(); iter++) {
			renewal2.push_back(iter->num);
			renewal2.push_back(iter->cnt);
		}

		for (int j = 0; j < row_cnt; j++) {
			arr[j][i] = 0;
		}


		int renewal2_size = renewal2.size();
		for (int j = 0; j < renewal2_size; j++) {
			if (j == 100) break;
			arr[j][i] = renewal2[j];
		}

		if (max_len < renewal2.size()) max_len = renewal2_size;
	}

	if (max_len > 100) max_len = 100;
	row_cnt = max_len;
}


int main()
{
	int temp;
	vector<int> insert;
	int res = 0;
	scanf("%d %d %d", &r, &c, &k);

	for (int i = 0; i < 3; i++) {
		insert.clear();
		for (int j = 0; j < 3; j++) {
			scanf("%d", &temp);
			arr[i][j] = temp;
		}

	}

	row_cnt = 3;
	col_cnt = 3;

	while (1) {
		if (res > 100) break;

		if (arr[r - 1][c - 1] == k) {
			break;
		}

		if (row_cnt >= col_cnt) row_calc();
		else col_calc();

		res++;

	}

	if (res == 101) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", res);
	}


	return 0;
}