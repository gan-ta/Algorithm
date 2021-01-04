#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int group_num = 1;
int visited[301][301];
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };
vector<int> parent;
vector<pair<int, pair<int, int>>> edge;
queue<pair<int, int>> q;


int get_parent(int search) {
	if (parent[search] == search) return search;

	return parent[search] = get_parent(parent[search]);
}

void union_parent(int a, int b) {
	int a_parent = get_parent(a);
	int b_parent = get_parent(b);

	parent[a_parent] = b_parent;
}

int solution(vector<vector<int>> land, int height) {
	int answer = 0;

	int row_size = land.size();
	int col_size = land.size();

	//그룹을 지어줌
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			if (visited[i][j] == 0) {
				group_num++;
				q.push(make_pair(i, j));
				visited[i][j] = group_num;
			}

			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int nr = r + dr[k];
					int nc = c + dc[k];

					if (nr < 0 || nr >= row_size || nc < 0 || nc >= col_size) continue;

					if (visited[nr][nc] == 0 && abs(land[r][c] - land[nr][nc]) <= height) {
						visited[nr][nc] = group_num;
						q.push(make_pair(nr, nc));
					}
				}
			}

		}
	}

	//그룹의 연결 정보를 저장
	for (int i = 0; i < row_size; i++) {
		for (int j = 0; j < col_size; j++) {
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (nr < 0 || nr >= row_size || nc < 0 || nc >= col_size) continue;
				
				if (visited[i][j] != visited[nr][nc]) {
					edge.push_back(make_pair(abs(land[i][j] - land[nr][nc]), make_pair(visited[i][j], visited[nr][nc])));
				}
				
			}
		}
	}
	
	int edge_size = edge.size();
	parent.resize(group_num+1);
	sort(edge.begin(), edge.end());
	for (int i = 0; i < group_num+1; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < edge_size; i++) {
		if (get_parent(edge[i].second.first) != get_parent(edge[i].second.second)) {
			union_parent(edge[i].second.first, edge[i].second.second);
			answer += edge[i].first;
		}
	}
	return answer;
}
