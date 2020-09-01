#include <cstdio>
using namespace std;

int up = 0;
int down = 0;
int front = 0;
int back = 0;
int right = 0;
int left = 0;

int n, m, x, y, k;

int map[20][20];

int move_dice[1000];

//동쪽 움직임
void east_action() {
	int temp_up = up;
	int temp_down = down;
	int temp_front = front;
	int temp_back = back;
	int temp_right = right;
	int temp_left = left;

	right = temp_up;
	down = temp_right;
	left = temp_down;
	up = temp_left;


}

//서쪽 움직임
void west_action() {
	int temp_up = up;
	int temp_down = down;
	int temp_front = front;
	int temp_back = back;
	int temp_right = right;
	int temp_left = left;

	up = temp_right;
	left = temp_up;
	down = temp_left;
	right = temp_down;
	

}

//북쪽 움직임
void north_action() {
	int temp_up = up;
	int temp_down = down;
	int temp_front = front;
	int temp_back = back;
	int temp_right = right;
	int temp_left = left;

	up = temp_front;
	back = temp_up;
	down = temp_back;
	front = temp_down;

}

//남쪽 움직임
void south_action() {
	int temp_up = up;
	int temp_down = down;
	int temp_front = front;
	int temp_back = back;
	int temp_right = right;
	int temp_left = left;

	front = temp_up;
	down = temp_front;
	back = temp_down;
	up = temp_back;
}

int main()
{

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		scanf("%d", &move_dice[i]);
	}

	for (int i = 0; i < k; i++) {
		//동
		if (move_dice[i] == 1) {
			int nx = x;
			int ny = y + 1;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			east_action();

			if (map[nx][ny] == 0){
				map[nx][ny] = down;
			}
			else{
				down = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx;
			y = ny;
		}
		//서
		else if (move_dice[i] == 2) {
			int nx = x;
			int ny = y - 1;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			west_action();

			if (map[nx][ny] == 0){
				map[nx][ny] = down;
			}
			else {
				down = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx;
			y = ny;

		}
		//북
		else if (move_dice[i] == 3) {
			int nx = x - 1;
			int ny = y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			north_action();
			if (map[nx][ny] == 0) {
				map[nx][ny] = down;
			}
			else {
				down = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx;
			y = ny;

		}
		//남
		else if (move_dice[i] == 4) {
			int nx = x+1;
			int ny = y;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			south_action();
			if (map[nx][ny] == 0) {
				map[nx][ny] = down;
			}
			else {
				down = map[nx][ny];
				map[nx][ny] = 0;
			}
			x = nx;
			y = ny;

		}
		printf("%d\n", up);
	}


	return 0;
}