#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> dot;
    vector<double> area;
    int num = k, cnt =0;
    dot.push_back(num);
    while(num != 1){
        cnt++;
        if(num %2 == 0) num /= 2;
        else num = num*3 +1;
        dot.push_back(num);
    }
    // 각 넓이 저장
    for(int i=0; i< dot.size() -1; i++){
        if(dot[i] > dot[i+1]){
            double a = (double)(dot[i] - dot[i+1]) /2 + dot[i+1];
            area.push_back(a);
        }else{
            double a = (double)(dot[i+1] - dot[i])/2 + dot[i];
            area.push_back(a);
        }
    }
    for(int i =0; i< ranges.size(); i++){
        int x1 = ranges[i][0];
        int x2 = dot.size() + ranges[i][1] -1;
        if(x1 == x2) answer.push_back(0.0);
        else if(x1>x2) answer.push_back(-1.0);
        else{
            double dot_area =0;
            for(int i=x1; i<x2; i++){
                dot_area += area[i];
            }
            answer.push_back(dot_area);
        }
    }
    return answer;
}