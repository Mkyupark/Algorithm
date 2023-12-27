#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<long long> CircleIn(int dis){
    vector<long long> answer(2,0);
    int pos_x = dis;
    int d = dis*dis;
    for(int pos_y =0; pos_y<dis; pos_y++){
        int ySquared = pos_y * pos_y;
        int z = ySquared + pos_x * pos_x;
        if(d < z){
            pos_x-=1;
            pos_y--;
            // answer[0]+=pos_x;
        }else if(d == z){
            pos_x -=1;
            answer[0]+=pos_x;
            answer[1]++;
        } else {answer[0]+=pos_x;}
    }
    return answer;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    vector<long long> v1 = CircleIn(r1);
    vector<long long> v2 = CircleIn(r2);
    answer = v2[0] - v1[0] + v2[1];
    cout <<v1[0] << " " << v1[1] <<" " <<v2[0] << " " << v2[1];
    answer*=4;
    return answer;
}