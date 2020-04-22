#include <cstdio>
#include <map>
#include <deque>
using namespace std;

typedef struct info {
	int r;
	int c;
};

int dir[10001];
deque<info> snake;

int game_map[101][101];

int dc[4] = { 1,0,-1,0 };
int dr[4] = { 0,1,0,-1 };

int r, c;
int i, j;
int n, k, l;
char d;
int time;


int main()
{
	int res = 0;
	int direction = 0;
	int nr, nc;
	char temp;
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &r, &c);
		game_map[r-1][c-1] = 1;
	}
	
	scanf("%d", &l);


	for (i = 0; i < l; i++)
	{
		scanf("%d", &time);
		scanf("%c", &temp);
		scanf("%c", &d);
		if (d == 'L') dir[time] = -1;
		else if (d == 'D') dir[time] = 1;
	}
	
	snake.push_front({ 0,0 });
	game_map[0][0] = 2;

	while (1)
	{
		info head = snake.front();

		nr = head.r + dr[direction];
		nc = head.c + dc[direction];

		if (nr < 0 || nr >= n || nc <0 || nc >= n || game_map[nr][nc] == 2) break;

		if (game_map[nr][nc] == 1)
		{
			snake.push_front({ nr,nc });
			game_map[nr][nc] = 2;
		}
		else if (game_map[nr][nc] == 0)
		{
			snake.push_front({ nr,nc });
			game_map[nr][nc] = 2;

			info cut = snake.back();
			snake.pop_back();
			game_map[cut.r][cut.c] = 0;

		}

		res++;
		if (direction + dir[res] >= 0) direction = (direction + dir[res]) % 4;
		else direction = 3;
	}

	printf("%d\n", res + 1);

	return 0;
}