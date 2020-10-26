#include <iostream>
using namespace std;

typedef struct info{
    int x1;
    int y1;
    int x2;
    int y2;
}info;

long long solution(int w, int h){
    long long answer = 0;

    double a = ((double)-h/(double)w);
    int b = h;
    int aim;

    for(int i = 0 ; i < w-1; i++){
        int aim  = a*(i+1) + b;
        answer += aim;
    }

    return answer * 2;
}


int main(){

    cout << solution(8,12)<<endl;
    return 0;
}