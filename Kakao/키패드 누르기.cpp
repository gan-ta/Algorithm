#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef struct location {
    int r;
    int c;
}location;

location left_hand = { 3,0 }, right_hand = { 3,2 };

int distance(location loc, int pad_num) {

    if (pad_num != 0) return  abs(loc.r - ((pad_num-1) / 3)) + abs(loc.c - ((pad_num-1) % 3));
    else return abs(loc.r - 3) + abs(loc.c - 1);
}

void move_right(string *answer, int pad_num) {
    *answer += "R";

    if (pad_num != 0) 
        right_hand = { (pad_num - 1) / 3, (pad_num - 1) % 3 };
    
    else 
        right_hand = { 3, 1 };
    

}

void move_left(string *answer, int pad_num) {
    *answer += "L";
    if (pad_num != 0)
        left_hand = { (pad_num - 1) / 3, (pad_num - 1) % 3 };

    else
        left_hand = { 3, 1 };
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int v_size = numbers.size();

    for (int i = 0; i < v_size; i++) {

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) move_left(&answer, numbers[i]); 
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) move_right(&answer, numbers[i]);   
        else {
            int dist_left = distance(left_hand, numbers[i]);
            int dist_right = distance(right_hand, numbers[i]);

            if (dist_left > dist_right) move_right(&answer, numbers[i]);
            else if (dist_left < dist_right) move_left(&answer, numbers[i]);
            else {
                if (hand.compare("right") == 0) move_right(&answer, numbers[i]);
                else move_left(&answer, numbers[i]);
            }
        }
    }

    return answer;
}

int main() {
    vector<int> numbers;
    numbers.push_back(7);
    numbers.push_back(0);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);

    string hand = "left";

   solution(numbers, hand);
}