#include <cstdio>
#include <string>
using namespace std;

int map[20][20];
int answer = 0;

typedef struct info {
	int r;
	int c;
}info;

info up_action(info info) {
	int nr = info.r - 1;
	int nc = info.c;

	if (nr < 0 || nr > 10 || nc < 0 || nc > 10) return info;

	if ((map[info.r][info.c] & 1) == 0) {
		map[info.r][info.c] += 1;
		map[nr][nc] += 2;
		answer++;
	}

	return {nr,nc};
}

info down_action(info info) {
	int nr = info.r + 1;
	int nc = info.c;

	if (nr < 0 || nr > 10 || nc < 0 || nc > 10) return info;

	if ((map[info.r][info.c] & 2) == 0) {
		map[info.r][info.c] += 2;
		map[nr][nc] += 1;
		answer++;
	}

	return { nr,nc };
}

info left_action(info info) {
	int nr = info.r;
	int nc = info.c - 1;

	if (nr < 0 || nr > 10 || nc < 0 || nc > 10) return info;


	if ((map[info.r][info.c] & 4) == 0) {
		map[info.r][info.c] += 4;
		map[nr][nc] += 8;
		answer++;
	}

	return { nr,nc };
}

info right_action(info info) {
	int nr = info.r;
	int nc = info.c + 1;

	if (nr < 0 || nr > 10 || nc < 0 || nc > 10) return info;

	if ((map[info.r][info.c] & 8) == 0) {
		map[info.r][info.c] += 8;
		map[nr][nc] += 4;
		answer++;
	}

	return { nr,nc };
}

int solution(string dir) {

	int str_size = dir.size();

	info info = { 5,5 };

	for (int i = 0; i < str_size; i++) {
		if (dir[i] == 'U') {
			info = up_action(info);
		}
		if (dir[i] == 'D') {
			info = down_action(info);
		}
		if (dir[i] == 'L') {
			info = left_action(info);
		}
		if (dir[i] == 'R') {
			info = right_action(info);
		}
	}
	return answer;
}

int main() {
	printf("%d ", solution("LULLLLLLU"));
	return 0;
}