#include <cstdio>
using namespace std;

int n,l;

int map[101][101];

bool row_check(int row_num) {

	//���ʿ��� ����������
	int location_check[101] = {0,};
	int temp;
	int cnt = 0;
	temp = map[row_num][0];
	cnt = 1;
	for (int i = 1; i < n; i++) {
		//���� ���
		if (temp == map[row_num][i]) {
			cnt++;
		}
		//�������� ���
		else if (temp > map[row_num][i]) {
			if (temp - map[row_num][i] > 1) {
				return false;
			}
			cnt = 1;
			temp = map[row_num][i];
		}
		//�ö󰡴� ���
		else {
			if (map[row_num][i] - temp > 1) {
				return false;
			}

			if (cnt < l) {
				return false;
			}
			else {
				for (int j = i - 1; j >= i - l; j--) {
					if (location_check[j] == 1) return false;
					location_check[j] = 1;
				}

				cnt = 1;
				temp = map[row_num][i];
			}

		}
	}


	//�����ʿ��� ��������
	temp = map[row_num][n-1];
	cnt = 1;
	for (int i = n-2; i >= 0; i--) {
		//���� ���
		if (temp == map[row_num][i]) {
			cnt++;
		}
		//�������� ���
		else if (temp > map[row_num][i]) {
			if (temp - map[row_num][i] > 1) {
				return false;
			}
			cnt = 1;
			temp = map[row_num][i];
		}
		//�ö󰡴� ���
		else {
			if (map[row_num][i] - temp > 1) {
				return false;
			}

			if (cnt < l) {
				return false;
			}
			else {
				for (int j = i+1 ; j  <= i + l; j++) {
					if (location_check[j] == 1) return false;
					location_check[j] = 1;
				}
				cnt = 1;
				temp = map[row_num][i];
			}

		}
	}
	
	return true;

}

bool col_check(int col_num) {

	//������ �Ʒ���
	int location_check[101] = { 0, };
	int temp;
	int cnt = 0;
	temp = map[0][col_num];
	cnt = 1;
	for (int i = 1; i < n; i++) {
		//���� ���
		if (temp == map[i][col_num]) {
			cnt++;
		}
		//�������� ���
		else if (temp > map[i][col_num]) {
			if (temp - map[i][col_num] > 1) {
				return false;
			}
			cnt = 1;
			temp = map[i][col_num];

		}
		//�ö󰡴� ���
		else {
			if (map[i][col_num] - temp > 1) {
				return false;
			}

			if (cnt < l) {
				return false;
			}
			else {
				for (int j = i - 1; j >= i - l; j--) {
					if (location_check[j] == 1) return false;
					location_check[j] = 1;
				}
				cnt = 1;
				temp = map[i][col_num];
			}

		}
	}

	temp = map[n-1][col_num];
	cnt = 1;
	for (int i = n - 2; i >= 0; i--) {
		//���� ���
		if (temp == map[i][col_num]) {
			cnt++;
		}
		//�������� ���
		else if (temp > map[i][col_num]) {
			if (temp - map[i][col_num] > 1) {
				return false;
			}
			cnt = 1;
			temp = map[i][col_num];
		}
		//�ö󰡴� ���
		else {
			if (map[i][col_num] - temp > 1) {
				return false;
			}
			if (cnt < l) {
				return false;
			}
			else {
				for (int j = i + 1; j <= i + l; j++) {
					if (location_check[j] == 1) return false;
					location_check[j] = 1;
				}
				cnt = 1;
				temp = map[i][col_num];
			}

		}
	}

	return true;

}

int main(){
	int res = 0;

	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (row_check(i)) res++;
		if (col_check(i)) res++;
	}

	printf("%d\n", res);

	return 0;
}