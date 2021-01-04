#include <string>
#include <vector>
using namespace std;

vector<int> renewal(string skill, string search) {
	vector<int> result;
	int str_size = search.size();

	for (int i = 0; i < str_size; i++) {
		if (skill.find(search[i]) != string::npos) {
			result.push_back(skill.find(search[i]));
		}
	}

	return result;
}

int solution(string skill, vector<string> skill_tree) {
	int answer = 0;

	int v_size = skill_tree.size();

	for (int i = 0; i < v_size; i++) {
		vector<int> search = renewal(skill,skill_tree[i]);
		int num = -1;
		int search_size = search.size();
		int flag = 0;

		for (int j = 0; j < search_size; j++) {
			if (num+1 != search[j]) {
				flag = 1;
				break;
			}
			num = search[j];
		}

		if (flag == 0) answer++;
	}

	return answer;
}
