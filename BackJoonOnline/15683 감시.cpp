#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int n, m;
int map[9][9];
vector<vector<int>> search;
int res = 100;

vector<pair<int,int>> up_check(int r, int c, vector<pair<int,int>> check) {

	for(int i = r - 1; i >= 0; i--) {
		if (map[i][c] == 6) break;
		
		if (map[i][c] == 0) {
			map[i][c] = 7;
			pair<int, int> insert(i, c);
			check.push_back(insert);
		}
	}
	return check;
}

vector<pair<int, int>> down_check(int r, int c, vector<pair<int,int>> check) {

	for (int i = r + 1; i < n; i++) {
		if (map[i][c] == 6) break;

		if (map[i][c] == 0) {
			map[i][c] = 7;
			pair<int, int> insert(i, c);
			check.push_back(insert);
		}
	}
	return check;
}

vector<pair<int, int>> left_check(int r, int c, vector<pair<int, int>> check) {

	for (int i = c - 1; i >= 0; i--) {
		if (map[r][i] == 6) break;

		if (map[r][i] == 0) {
			map[r][i] = 7;
			pair<int, int> insert(r, i);
			check.push_back(insert);
		}
	}
	return check;
}

vector<pair<int, int>> right_check(int r, int c, vector<pair<int, int>> check) {

	for (int i = c + 1; i < m; i++) {
		if (map[r][i] == 6) break;

		if (map[r][i] == 0) {
			map[r][i] = 7;
			pair<int, int> insert(r, i);
			check.push_back(insert);
		}
	}
	return check;
}


void reset_location(vector<pair<int, int>> check) {

	int s = check.size();

	for (int i = 0; i < s; i++) {
		map[check[i].first][check[i].second] = 0;
	}
}


void dfs(int idx) {

	if (idx == search.size()) {
		int count_zero = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					count_zero++;
				}
			}
		}

		if (res > count_zero) res = count_zero;
		return;
	}

	int r = search[idx][0];
	int c = search[idx][1];
	int cctv = search[idx][2];
	vector<pair<int, int>> look_location;


	if (cctv == 1) {

		//위를 감시
		look_location = up_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();


		//아래를 감시
		look_location = down_check(r, c,look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//왼쪽을 감시
		look_location = left_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//오른쪽을 감시
		look_location = right_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

	}
	else if (cctv == 2) {

		//위아래 감시
		look_location = up_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//왼쪽오른쪽 감시
		look_location = left_check(r, c, look_location);
		look_location = right_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();
	}
	else if (cctv == 3) {

		//위오른쪽 감시
		look_location = up_check(r, c, look_location);
		look_location = right_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//오른쪽 아래 감시
		look_location = right_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//아래쪽왼쪽 감시
		look_location = left_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//왼쪽위쪽 감시
		look_location = up_check(r, c, look_location);
		look_location = left_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();
	}
	else if (cctv == 4) {
		//위 제외
		look_location = right_check(r, c, look_location);
		look_location = left_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();
		
		//오른쪽 제외
		look_location = up_check(r, c, look_location);
		look_location = left_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//아래쪽 제외 
		look_location = right_check(r, c, look_location);
		look_location = left_check(r, c, look_location);
		look_location = up_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();

		//왼쪽 제외
		look_location = right_check(r, c, look_location);
		look_location = up_check(r, c, look_location);
		look_location = down_check(r, c, look_location);
		dfs(idx + 1);
		reset_location(look_location);
		look_location.clear();


	}
	else if (cctv == 5) {

	//전 방향 감시
	look_location = right_check(r, c, look_location);
	look_location = up_check(r, c, look_location);
	look_location = down_check(r, c, look_location);
	look_location = left_check(r, c, look_location);
	dfs(idx + 1);
	reset_location(look_location);
	look_location.clear();

	}

}


int main()
{
	int s;

	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6) {
				vector<int> insert;
				insert.push_back(i);
				insert.push_back(j);
				insert.push_back(map[i][j]);
				search.push_back(insert);
			}
		}
	}

	dfs(0);


	printf("%d\n", res);

	return 0;
}