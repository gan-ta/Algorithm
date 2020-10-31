#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
	return a > b;
}

bool asc(int a, int b) {
	return a < b;
}

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	int a_size = A.size();
	int b_size = B.size();

	sort(A.begin(), A.end(),asc);
	sort(B.begin(), B.end(), asc);

	int search_idx = 0;

	for (int i = 0; i < a_size; i++) {
		int check = 0;
		for (int j = search_idx; j < b_size; j++) {
			if (A[i] < B[j]) {
				search_idx = j + 1;
				answer++;
				check = 1;
				break;
			}
		}

		if (check == 0) break;
	}

	return answer;
}