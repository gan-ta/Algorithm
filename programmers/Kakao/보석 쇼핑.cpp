#include <set>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>
using namespace std;


vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> jewelry;
    set<string> search;
    pair<int, int> check;
    map<string, int> count;
    int v_size;
    int aim_size;
    int start = 0, end = 0;
    int len;

    v_size = gems.size();

    for (int i = 0; i < v_size; i++) {
        jewelry.insert(gems[i]);
    }
    aim_size = jewelry.size();

    check = make_pair(0, aim_size - 1);

    len = gems.size()+1;
    
    count[gems[0]]++;
    search.insert(gems[0]);

    if (search.size() == aim_size) {
        if (len > (end - start + 1)) {
            check.first = start;
            check.second = end;
            len = end - start + 1;
        }
    }

    while (true) {

        if (start == end && end == v_size - 1) break;

        if (search.size() == aim_size) {

            if (len > (end - start + 1)) {
                check.first = start;
                check.second = end;
                len = end - start + 1;
            }
            
            count[gems[start]]--;

            if (count[gems[start]] == 0) search.erase(search.find(gems[start]));
            start++;
        }
        else {
            if (end != v_size - 1) {
                end++;
                count[gems[end]]++;
                search.insert(gems[end]);

            }
            else {
                count[gems[start]]--;
                if (count[gems[start]] == 0) search.erase(search.find(gems[start]));
                start++;
            }
        }
    }

    answer.push_back(check.first + 1);
    answer.push_back(check.second + 1);

    return answer;
}

int main() {

    vector<string> gems;

    gems.push_back("ZZZ");
    gems.push_back("YYY");
    gems.push_back("NNNN");
    gems.push_back("YYY");
    gems.push_back("BBB");


    vector<int> answer = solution(gems);


    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}