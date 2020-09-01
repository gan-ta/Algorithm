#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

typedef struct unit_location {
	int r;
	int c;
	int dir;
}unit_location;

int map[20][20];
int temp_map[20][20];

vector<deque<int>> unit_map[20];
vector<unit_location> location;

int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

int n, k;


bool simulation(int unit_index) {
	deque<int> move_unit;
	int nr, nc;

	//유닛에 대한 정보를 가져옴
	unit_location search = location[unit_index];

	//유닛까지 위에 있는 것을 움직일 후보군에 저장
	while (1) {
		if (unit_map[search.r][search.c].back() == unit_index) {
			move_unit.push_back(unit_map[search.r][search.c].back());
			unit_map[search.r][search.c].pop_back();
			break;
		}
		else {
			move_unit.push_back(unit_map[search.r][search.c].back());
			unit_map[search.r][search.c].pop_back();
		}
	}

	nr = search.r + dr[search.dir];
	nc = search.c + dc[search.dir];


	//초벌과정
	if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
		//방향을 바꾼다
		if (search.dir == 0) {
			location[unit_index].dir = 1;
			search.dir = 1;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 1) {
			location[unit_index].dir = 0;
			search.dir = 0;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 2) {
			location[unit_index].dir = 3;
			search.dir = 3;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 3) {
			location[unit_index].dir = 2;
			search.dir = 2;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
	}
	else if (map[nr][nc] == 2) {
		//방향을 바꾼다
		if (search.dir == 0) {
			location[unit_index].dir = 1;
			search.dir = 1;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 1) {
			location[unit_index].dir = 0;
			search.dir = 0;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 2) {
			location[unit_index].dir = 3;
			search.dir = 3;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
		else if (search.dir == 3) {
			location[unit_index].dir = 2;
			search.dir = 2;
			nr = search.r + dr[search.dir];
			nc = search.c + dc[search.dir];
		}
	}


	//메인과정
	//범위를 벗어나는 경우
	if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
		//제자리로 위치시켜줌
		while (!move_unit.empty()) {
			unit_map[search.r][search.c].push_back(move_unit.back());
			move_unit.pop_back();
		}

		if (unit_map[search.r][search.c].size() >= 4) return true;
	}
	//파란색인 경우
	else if (map[nr][nc] == 2) {
		//제자리로 위치시켜줌
		while (!move_unit.empty()) {
			unit_map[search.r][search.c].push_back(move_unit.back());
			move_unit.pop_back();
		}
		if (unit_map[search.r][search.c].size() >= 4) return true;
	}
	//흰색인 경우
	else if (map[nr][nc] == 0) {
		while (!move_unit.empty()) {
			unit_map[nr][nc].push_back(move_unit.back());
			//위치 정보를 갱신
			location[move_unit.back()].r = nr;
			location[move_unit.back()].c = nc;
			move_unit.pop_back();
		}
		if (unit_map[nr][nc].size() >= 4) return true;
	}
	//빨간색인 경우
	else if (map[nr][nc] == 1) {
		//제자리로 위치시켜줌
		while (!move_unit.empty()) {
			unit_map[nr][nc].push_back(move_unit.front());
			//위치정보를 갱신
			location[move_unit.front()].r = nr;
			location[move_unit.front()].c = nc;
			move_unit.pop_front();
		}
		if (unit_map[nr][nc].size() >= 4) return true;
	}

	return false;


}


int main() {
	deque<int> insert;
	int temp;
	int temp_r;
	int temp_c;
	int temp_dir;
	int res = 0;
	int check = 0;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			insert.clear();
			scanf("%d", &temp);
			
			if (temp != 0) {
				map[i][j] = temp;
			}
			unit_map[i].push_back(insert);
		}
	}

	location.push_back({ 0,0,0 });
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &temp_r, &temp_c, &temp_dir);
		unit_location insert;
		insert.r = temp_r - 1;
		insert.c = temp_c - 1;
		insert.dir = temp_dir - 1;
		location.push_back(insert);
		unit_map[insert.r][insert.c].push_back(i+1);
	}


	while (1) {
		if (res > 1000) break;

		res++;
	

		for (int i = 1; i <= k; i++) {
			if (simulation(i)) {
				check = 1;
				break;
			}
		}

		if (check == 1) break;
	}

	if (check == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d\n", res);
	}

	return 0;
}