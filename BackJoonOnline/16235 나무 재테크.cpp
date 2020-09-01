#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct tree {
	int r;
	int c;
	int age;
};

deque <tree> trees;
vector<tree> finish;
vector<tree> expansion;

int map[11][11];
int A[11][11];

int N, M, K;

int dr[8] = { 1,0,-1,0,1,1,-1,-1};
int dc[8] = { 0,1,0,-1,1,-1,1,-1 };

int vector_size;
int year = 0;

bool sort_condition(tree a, tree b) {
	if (a.age < b.age) {
		return true;
	}
	else {
		return false;
	}
}

void spring_action() {
	deque<tree> temp_trees;
	vector_size = trees.size();

	for (int i = 0; i < vector_size; i++) {
		tree tree_search = trees[i];
		
		if (map[tree_search.r][tree_search.c] + (A[tree_search.r][tree_search.c] * year) >= tree_search.age) {

			map[tree_search.r][tree_search.c] -= tree_search.age;
			tree_search.age += 1;

			if (tree_search.age % 5 == 0) {
				expansion.push_back(tree_search);
			}

			temp_trees.push_back(tree_search);
		}
		else {
			finish.push_back(tree_search);
		}
	}

	trees = temp_trees;

}

void summer_action() {
	vector_size = finish.size();

	for (int i = 0; i < vector_size; i++) {
		tree tree_search = finish[i];

		map[tree_search.r][tree_search.c] += (tree_search.age/2);
	}

	finish.clear();
}

void autumn_action() {
	vector_size = expansion.size();

	int nr, nc;

	for (int i = 0; i < vector_size; i++) {
		tree tree_search = expansion[i];

		for (int j = 0; j < 8; j++) {
			nr = tree_search.r + dr[j];
			nc = tree_search.c + dc[j];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			trees.push_front({ nr,nc,1 });
		}

	}
	expansion.clear();
	
}


int main() {
	int temp_r, temp_c, temp_age;
	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &temp_r, &temp_c, &temp_age);

		trees.push_back({ temp_r-1,temp_c-1,temp_age });
	}

	sort(trees.begin(), trees.end(), sort_condition);

	for (int i = 0; i < K; i++) {
		spring_action();
		summer_action();
		autumn_action();
		year++;
	}

	printf("%d\n", trees.size());

	return 0;
}