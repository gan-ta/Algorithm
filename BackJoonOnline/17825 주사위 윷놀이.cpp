#include <cstdio>
#include <vector>
using namespace std;

int dice_num[10];

int map[50];
int score[50];
int blue_point[50];
int res = -1;

int unit[4]; //유닛의 위치를 결정

void map_setting() {
	//기본세팅
	for (int i = 0; i < 21; i++) {
		map[i] = i + 1;
	}
	map[21] = 21;

	//왼쪽
	map[22] = 23;
	map[23] = 24;
	map[24] = 30;

	//아래쪽
	map[25] = 26;
	map[26] = 30;

	//오른쪽
	map[27] = 28;
	map[28] = 29;
	map[29] = 30;

	//중간
	map[30] = 31;

	//위로
	map[31] = 32;
	map[32] = 20;

	blue_point[5] = 22;
	blue_point[10] = 25;
	blue_point[15] = 27;

}

void score_setting() {
	//기본세팅
	for (int i = 0; i < 21; i++) {
		score[i] = i * 2;
	}
	score[21] = 0;

	//왼쪽
	score[22] = 13;
	score[23] = 16;
	score[24] = 19;

	//아래쪽
	score[25] = 22;
	score[26] = 24;

	//오른쪽
	score[27] = 28;
	score[28] = 27;
	score[29] = 26;

	//중간
	score[30] = 25;
	
	//위로
	score[31] = 30;
	score[32] = 35;
}

void dfs(int depth, int sum) {

	if (depth == 10) {
		if (res < sum) {
			res = sum;
		}
		return;
	}

	//유닛마다 이동을 시키고 고려
	for (int i = 0; i < 4; i++) {
		int unit_point = unit[i];
		int move_dist = dice_num[depth];
		int next_point = unit_point;
		int check = 0;

		//이미 도착점에 있는 것은 고려 해 주지 않음
		if (unit_point == 21) continue;

		if (blue_point[unit_point] != 0) {
			next_point = blue_point[next_point];
		}
		else {
			next_point = map[next_point];
		}

		//해당 점으로 이동을 시켜보기
		for (int j = 1; j < move_dist; j++) {
			next_point = map[next_point];
		}

		//이동시킨 곳에 이미 말이 있는지 확인
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;

			if (next_point == unit[j] && next_point != 21){
				check = 1;
				break;
			}
		}
		if (check == 1) continue;

		unit[i] = next_point;
		dfs(depth + 1, sum + score[next_point]);
		unit[i] = unit_point;

	}
	

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &dice_num[i]);
	}

	map_setting();
	score_setting();

	dfs(0, 0);

	printf("%d\n", res);

	return 0;
}