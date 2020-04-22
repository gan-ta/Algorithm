#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int n;

typedef struct zero {
	int r;
	int c;
}zero;

bool check_block1(vector<vector<int>>& board, int r, int c)
{
	int i, j;
	int num = -1;
	int cnt = 0;
	vector<zero> zero_list;

	if (r >= n - 1 || c >= n - 2) return false;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (board[r + i][c + j] == 0)
			{
				zero_list.push_back({ r + i,c + j });
				continue;
			}
			if (num != -1 && num != board[r + i][c + j]) return false;
			if (num == -1)
			{
				num = board[r + i][c + j];
				cnt++;
			}
			else if (num == board[r + i][c + j])
			{
				cnt++;
			}
		}
	}
	if (num == -1) return false;
	if (cnt != 4) return false;

	for (i = 0; i < zero_list.size(); i++)
	{
		zero search = zero_list[i];
		for (j = 0; j < search.r; j++)
		{
			if (board[j][search.c] != 0) return false;
		}
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			board[r + i][c + j] = 0;
		}
	}

	return true;
}

bool check_block2(vector<vector<int>>& board, int r, int c)
{
	int i, j;
	int num = -1;
	int cnt = 0;
	vector<zero> zero_list;

	if (r >= n - 2 || c >= n - 1) return false;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (board[r + i][c + j] == 0)
			{
				zero_list.push_back({ r + i,c + j });
				continue;
			}
			if (num != -1 && num != board[r + i][c + j]) return false;
			if (num == -1)
			{
				num = board[r + i][c + j];
				cnt++;
			}
			else if (num == board[r + i][c + j])
			{
				cnt++;
			}
		}
	}

	if (num == -1) return false;
	if (cnt != 4) return false;

	for (i = 0; i < zero_list.size(); i++)
	{
		zero search = zero_list[i];
		for (j = 0; j < search.r; j++)
		{
			if (board[j][search.c] != 0) return false;
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			board[r + i][c + j] = 0;
		}
	}

	return true;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	int i, j;

	n = board.size();

	while (1)
	{
		bool check = false;
		for (i = 0; i < board.size(); i++)
		{
			for (j = 0; j < board[i].size(); j++)
			{
				check = check_block1(board, i, j);
				if (!check)
				{
					check = check_block2(board, i, j);
				}
				if (check)
				{
					answer++;
					break;
				}
			}
			if (check) break;
		}
		if (!check) break;
	}
	return answer;
}