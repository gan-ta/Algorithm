#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;

vector<pair<int, int>> turn_info;
deque<int> gear[4];
int match_status[3]; //현재 맞물려 있는 상태를 저장
int turn_check[4];

void reverse_clock(int index) {

	int insert = gear[index].front();
	gear[index].pop_front();
	gear[index].push_back(insert);

}

void clock(int index) {

	int insert = gear[index].back();
	gear[index].pop_back();
	gear[index].push_front(insert);

}

void clac_match() {

	//0번과1번의 상태
	if (gear[0][2] == gear[1][6]) {
		match_status[0] = 1;
	}
	else {
		match_status[0] = 0;
	}

	//1번과2번의 상태
	if (gear[1][2] == gear[2][6]) {
		match_status[1] = 1;
	}
	else {
		match_status[1] = 0;
	}

	//2번과 3번의 상태
	if (gear[2][2] == gear[3][6]) {
		match_status[2] = 1;
	}
	else {
		match_status[2] = 0;
	}

}


int main()
{
	int k;
	int s;
	int res = 0;


	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < 8; j++) {
			gear[i].push_back(temp[j] - 48);
		}
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		pair<int, int> insert;
		int temp;
		cin >> temp;
		insert.first = temp - 1;
		cin >> insert.second;
		turn_info.push_back(insert);
	}


	clac_match();

	s = turn_info.size();

	for (int i = 0; i < s; i++) {
		memset(turn_check, 0, sizeof(turn_check));
		pair<int, int> out;
		out = turn_info[i];
		int clock_check = out.second;

		if (clock_check == 1) {
			clock(out.first);
		}
		else {
			reverse_clock(out.first);
		}

		for(int j = out.first - 1; j >= 0; j--) {
			if (match_status[j] == 0) {

				if (clock_check == 1) {
					//마주보는 것은 반시계로
					reverse_clock(j);
					clock_check = -1;
				}
				else if (clock_check == -1) {
					//마주보는 것은 시계로
					clock(j);
					clock_check = 1;
				}

			}
			else {
				break;
			}
		}

		clock_check = out.second;

		for (int j = out.first + 1; j < 4; j++) {
			if (match_status[j-1] == 0) {

				if (clock_check == 1) {
					//마주보는 것은 반시계로
					reverse_clock(j);
					clock_check = -1;
				}
				else if (clock_check == -1) {
					//마주보는 것은 시계로
					clock(j);
					clock_check = 1;
				}

			}
			else {
				break;
			}

		}
		clac_match();
	}
	

	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1) {
			res += pow(2, i);
		}
	}

	printf("%d\n", res);

	return 0;
}