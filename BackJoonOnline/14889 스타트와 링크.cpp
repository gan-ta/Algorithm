#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int num;
int map[21][21];
int diff = -1;
vector<int> team1;
vector<int> team2;


void set_team(int group) {

	for (int i = 0; i < num; i++) {

		if (group % 2 == 0) {
			team1.push_back(i);
		}
		else {
			team2.push_back(i);
		}
		group = group >> 1;
	}

}

void calc_diff() {
	int s1 = team1.size();
	int s2 = team2.size();
	int sum1 = 0;
	int sum2 = 0;
	int temp_diff;

	for (int i = 0; i < s1; i++) {
		for (int j = i + 1; j < s1; j++) {
			sum1 += (map[team1[i]][team1[j]] + map[team1[j]][team1[i]]);
		}
	}

	for (int i = 0; i < s2; i++) {
		for (int j = i + 1; j < s2; j++) {
			sum2 += (map[team2[i]][team2[j]] + map[team2[j]][team2[i]]);
		}
	}

	temp_diff = abs(sum1 - sum2);

	if (diff == -1 || temp_diff < diff) {
		diff = temp_diff;

	}
}



int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%d", &map[i][j]);
		}
	}


	for (int i = 0; i < pow(2, num); i++) {
		team1.clear();
		team2.clear();

		set_team(i);
		if (team1.size() != num / 2) continue;
		calc_diff();

	}



	printf("%d\n", diff);


	return 0;
}