#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct virus {
	int r;
	int c;
	int depth;
}virus;

int N, M;

int map[51][51];
int visited[51][51];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int vector_size;

vector<virus> viruses;
vector<int> group;

int aim = 0;
int ans = 1000000;


void simulation(queue<virus> *q) {
	virus search;
	virus insert;
	int nr, nc;
	int res = 0;
	int check = 0;
	int occupy_count = 0;

	while (!q->empty()) {
		search = q->front();
		q->pop();
		

		if (occupy_count == aim) { check = 2; break; }
		
		for (int i = 0; i < 4; i++) {
			nr = search.r + dr[i];
			nc = search.c + dc[i];


			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;


			if (map[nr][nc] != 1 && visited[nr][nc] == 0) {
				insert.r = nr;
				insert.c = nc;
				insert.depth = search.depth + 1;
				q->push(insert);
				visited[nr][nc] = 1;
				if (map[nr][nc] == 0) occupy_count++;
				if (insert.depth >= ans) { check = 1;  break; }
				else res = insert.depth;
			}
		}
		if (check == 1) break;
	}

	while (!q->empty()) {
		q->pop();
	}

	if (check == 2) {
		if (ans > res) ans = res;
	}

}

int main() {

	virus insert;
	queue<virus> q;
	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);

			if (map[i][j] == 2){
				insert.r = i;
				insert.c = j;
				insert.depth = 0;
				viruses.push_back(insert);
			}

			if (map[i][j] == 0) aim++;
						
		}
	}

	vector_size = viruses.size();


	for (int i = 0; i < vector_size; i++) {
		if (i < M) {
			group.push_back(1);
		}
		else {
			group.push_back(0);
		}
	}

	sort(group.begin(), group.end());


	do {
		
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < vector_size; i++) {
			if (group[i] == 1) {
				q.push(viruses[i]);
				visited[viruses[i].r][viruses[i].c] = 1;
			}
		}

		simulation(&q);

	} while (next_permutation(group.begin(), group.end()));

	if (ans != 1000000) {
		printf("%d\n", ans);
	}
	else {
		printf("%d\n", -1);
	}



	return 0;
}