#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int INF = 10000000;

vector<pair<int, int>> map[51];
int result[51];

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};


void dijkstra(int start) {

    result[start] = 0;
    priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> pq;

    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int n = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        for (int i = 0; i < map[n].size(); i++) {
            int search_n = map[n][i].first;
            int search_d = d + map[n][i].second;

            if (search_d < result[search_n]) {
                result[search_n] = search_d;
                pq.push(make_pair(search_n, search_d));
            }
        }
    }
}


int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

    for (int i = 0; i <= N; i++) {
        result[i] = INF;
    }

    for (int i = 0; i < road.size(); i++) {
        map[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        map[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }

    dijkstra(1);

    for (int i = 1; i <= N; i++) {
        if (result[i] <= K)answer++;
    }

	return answer;
}

int main() {

    vector<vector<int>> test;
    vector<int> insert;

    insert.push_back(1);
    insert.push_back(2);
    insert.push_back(1);
    test.push_back(insert);
    insert.clear();

    insert.push_back(2);
    insert.push_back(3);
    insert.push_back(3);
    test.push_back(insert);
    insert.clear();

    insert.push_back(5);
    insert.push_back(2);
    insert.push_back(2);
    test.push_back(insert);
    insert.clear();

    insert.push_back(1);
    insert.push_back(4);
    insert.push_back(2);
    test.push_back(insert);
    insert.clear();

    insert.push_back(5);
    insert.push_back(3);
    insert.push_back(1);
    test.push_back(insert);
    insert.clear();

    insert.push_back(5);
    insert.push_back(4);
    insert.push_back(2);
    test.push_back(insert);
    insert.clear();



    printf("%d\n", solution(5, test, 3));

    return 0;
}