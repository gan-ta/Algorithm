#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int map[21][21];
int visited[21][21];

int N;
int dr[4] = { 1,0,-1,-0 };
int dc[4] = { 0,1,0,-1 };

typedef struct location{
	int r;
	int c;
	int size;
	int depth;
	int eat_check;
}location;

queue<location> q;
queue<location> temp_q;

bool sort_location(location a, location b) {

	if (a.r < b.r) {
		return true;
	}
	else if (a.r == b.r) {
		if (a.c < b.c) return true;
		else return false;
	}

	return false;
}

int main() {
	int res = 0;
	int nr, nc;
	int check = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 9) {
				map[i][j] = 0;
				q.push({ i,j,2,0,0 });
				visited[i][j] = 1;
			}
		}
	}

	
	while (!q.empty()) {
		check = 0;
		while (!temp_q.empty()) temp_q.pop();

		while (!q.empty()) {
			location search = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				nr = search.r + dr[i];
				nc = search.c + dc[i];

				if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
					continue;
				}

				if (visited[nr][nc] == 1) continue;

				if (map[nr][nc] == 0 && visited[nr][nc] == 0) {
					temp_q.push({ nr,nc,search.size,search.depth + 1,search.eat_check });
					visited[nr][nc] = 1;
				}
				else if (map[nr][nc] == search.size && visited[nr][nc] == 0) {
					temp_q.push({ nr,nc,search.size,search.depth + 1,search.eat_check });
					visited[nr][nc] = 1;
				}
				else if (map[nr][nc] < search.size && visited[nr][nc] == 0) {
					check = 1;
					temp_q.push({ nr,nc,search.size,search.depth + 1,search.eat_check });
					visited[nr][nc] = 1;
				}
				
			}

		}

		if (check == 0) {
			q = temp_q;
		}
		else {

			vector<location> temp;

			//새로운 위치 출발점을 갱신
			while (!temp_q.empty()) {
				location search = temp_q.front();
				temp_q.pop();

				if (map[search.r][search.c] < search.size && map[search.r][search.c] != 0) {
					temp.push_back(search);
				}
			}

			sort(temp.begin(), temp.end(), sort_location);

			location detect = temp[0];
			map[detect.r][detect.c] = 0;
			memset(visited, 0, sizeof(visited));
			res = detect.depth;

			if (detect.eat_check + 1 == detect.size) {
				q.push({ detect.r,detect.c,detect.size + 1,detect.depth,0 });
				visited[detect.r][detect.c] = 1;
			}
			else {
				q.push({ detect.r,detect.c,detect.size,detect.depth,detect.eat_check+1});
				visited[detect.r][detect.c] = 1;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}