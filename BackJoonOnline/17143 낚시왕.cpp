#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dr[5] = {0, -1,1,0,0 };
int dc[5] = {0, 0,0,1,-1 };

typedef struct shark {
	int r;
	int c;
	int s;//속력
	int d;//이동방향
	int z;//크기
}shark;


int R, C, M;
int fisher = -1;
int top;
int total = 0;
int top_location[101];

int map[101][101];
vector<shark> sharks;
int vector_size;


//크기가 큰 순서대로 정렬
bool cmp(shark a, shark b) {
	if (a.z > b.z) return true;
	else return false;
}


shark move_action(shark search) {
	shark res;
	int turn;
	int location;


	//위
	if (search.d == 1) {
		if (search.r >= search.s) {
			res.r = search.r - search.s;
			res.c = search.c;
			res.s = search.s;
			res.d = search.d;
			res.z = search.z;
			return res;
		}
		else {
			turn = (search.s - search.r) / (R- 1);
			location = (search.s - search.r) % (R - 1);

			if (turn % 2 == 1) res.d = 1;//위
			else res.d = 2;//아래

			if (res.d == 1) res.r = (R - 1) - location;
			else res.r = location;

			res.c = search.c;
			res.s = search.s;
			res.z = search.z;
			return res;
		}
	}
	//아래
	else if (search.d == 2) {
		if ((R - 1 - search.r) >= search.s) {
			res.r = search.r + search.s;
			res.c = search.c;
			res.s = search.s;
			res.d = search.d;
			res.z = search.z;
			return res;
		}
		else {
			turn = (search.s - ((R-1) - search.r)) / (R - 1);
			location = (search.s - ((R-1)-search.r)) % (R - 1);

			if (turn % 2 == 1) res.d = 2;//아래
			else res.d = 1;//위

			if (res.d == 1) res.r = (R - 1) - location;
			else res.r = location;

			res.c = search.c;
			res.s = search.s;
			res.z = search.z;
			return res;
		}
	}
	//오른쪽
	else if (search.d == 3) {
		if ((C - 1 - search.c) >= search.s) {
			res.r = search.r;
			res.c = search.c + search.s;
			res.s = search.s;
			res.d = search.d;
			res.z = search.z;
			return res;

		}
		else {
			turn = (search.s - ((C - 1) - search.c)) / (C - 1);
			location = (search.s - ((C - 1) - search.c)) % (C - 1);

			if (turn % 2 == 1) res.d = 3;
			else res.d = 4;

			if (res.d == 3) res.c = location;
			else res.c = (C - 1) - location;

			res.r = search.r;
			res.s = search.s;
			res.z = search.z;
			return res;
		}
	}
	//왼쪽
	else if (search.d == 4) {
		if (search.c >= search.s) {
			res.r = search.r;
			res.c = search.c - search.s;
			res.s = search.s;
			res.d = search.d;
			res.z = search.z;
			return res;
		}
		else {
			turn = (search.s - search.c) / (C - 1);
			location = (search.s - search.c) % (C - 1);

			if (turn % 2 == 1) res.d = 4;
			else res.d = 3;

			if (res.d == 3) res.c = location;
			else res.c = (C-1) - location;

			res.r = search.r;
			res.s = search.s;
			res.z = search.z;
			return res;

		}

	}

}

void first_simulation() {
	top = R;
	vector_size = sharks.size();

	for (int i = 0; i < vector_size; i++) {
		if (sharks[i].c == fisher) {
			if (top > sharks[i].r) {
				top = sharks[i].r;
			}
		}
	}
}


//상어를 잡는 과정
void second_simulation() {

	vector<shark> temp_sharks;
	vector_size = sharks.size();

	if (top == R) return;

	for (int i = 0; i < vector_size; i++) {
		if (sharks[i].r == top && sharks[i].c == fisher) {
			total += sharks[i].z;
		}
		else {
			temp_sharks.push_back(sharks[i]);
		}
	}
	sharks = temp_sharks;
	return;
}


void third_simulation() {
	vector<shark> temp_sharks;
	memset(map, 0, sizeof(map));

	vector_size = sharks.size();

	for (int i = 0; i < vector_size; i++) {
		shark after_move = move_action(sharks[i]);

		if (map[after_move.r][after_move.c] == 0) {
			map[after_move.r][after_move.c] = 1;
			temp_sharks.push_back(after_move);
		}
	}

	sharks = temp_sharks;

}




int main() {
	int temp_r, temp_c, temp_s, temp_d, temp_z;
	scanf("%d %d %d", &R, &C, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &temp_r, &temp_c, &temp_s, &temp_d, &temp_z);

		shark insert;
		insert.r = temp_r-1;
		insert.c = temp_c-1;
		insert.s = temp_s;
		insert.d = temp_d;
		insert.z = temp_z;

		sharks.push_back(insert);
	}

	sort(sharks.begin(), sharks.end(), cmp);


	while (1) {
		if (fisher >= C-1) break;
		fisher++;
		first_simulation();
		second_simulation();
		third_simulation();
	}

	printf("%d\n", total);
	return 0;

}
