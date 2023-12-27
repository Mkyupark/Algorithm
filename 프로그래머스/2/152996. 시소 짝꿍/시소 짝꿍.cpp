#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int addAnswer(int num1, int num2){
    if(num1 == num2 || num1*4 == num2*2 || num1*3 == num2*2 || num1*4 == num2*3){
        return 1;
    }
    else return 0;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for(int i =0; i< weights.size(); i++){
        for(int j =i+1; j <weights.size(); j++){
           answer += addAnswer(weights[i], weights[j]);
        }
    }
    return answer;
}