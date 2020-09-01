#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

typedef struct country {
	int r;
	int c;
	int unit;
}country;


int map[51][51];
int map_check[51][51];
int N, L, R;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

queue<country> q;
vector<vector<country>> group_list;


int main() {
	int res = 0;
	int start_check = 0;
	int nr, nc;
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (1) {

		memset(map_check, 0, sizeof(map_check));
		group_list.clear();
		

		for (int i = 0; i < N; i++) {
			for(int j = 0 ; j < N; j++){

				if (map_check[i][j] == 0) {
					start_check = 0;

					//그룹이 지얼질 수 있는지 확인하는 작업
					for (int k= 0; k < 4; k++) {
						nr = i + dr[k];
						nc = j + dc[k];

						if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
							if (abs(map[i][j] - map[nr][nc]) >= L && abs(map[i][j] - map[nr][nc]) <= R) {
								start_check = 1;

								break;
							}
						}
					}

					//그룹이 지어질 수 없으면 탐색하지 않음
					if (start_check == 0) continue;

					q.push({i,j,map[i][j]});
					map_check[i][j] = 1;
					vector<country> insert;
					insert.push_back({ i,j,map[i][j]});

					while (!q.empty()) {

						country search = q.front();
						q.pop();


						for (int k = 0; k < 4; k++) {
							nr = search.r + dr[k];
							nc = search.c + dc[k];


							if (nr >= 0 && nr < N && nc >= 0 && nc < N) {

								if (map_check[nr][nc] != 0) continue;

								if (abs(map[search.r][search.c] - map[nr][nc]) >= L && abs(map[search.r][search.c] - map[nr][nc]) <= R) {
									q.push({ nr,nc,map[nr][nc]});
									map_check[nr][nc] = 1;
									insert.push_back({ nr,nc,map[nr][nc]});
								}
							}
						}
						
					}

					group_list.push_back(insert);

				}

			}
		}

		
		if (group_list.size() == 0) {
			break;
		}
		else {
			int total = 0;
			int total_div = 0;

			int size1 = group_list.size();
			int size2;

			for (int i = 0; i < size1; i++) {
				total = 0;

				size2 = group_list[i].size();

				for (int j = 0; j < size2; j++) {
					total += group_list[i][j].unit;
				}

				total_div = (total / size2);

				for (int j = 0; j < size2; j++) {
					map[group_list[i][j].r][group_list[i][j].c] = total_div;
				}



			}
			res++;
		}

	}

	printf("%d", res);



	return 0;
}