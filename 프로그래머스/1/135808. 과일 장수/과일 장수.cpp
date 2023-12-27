#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) { 
    return a > b;
} 

void cal (int k, int m, int *answer){
    *answer+= k*m;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0; int len = score.size(); int box = len/m;
    sort(score.begin(), score.end(), cmp);
    int idx =0; int grade = score[0]; int temp =0;
    while(box--){
        for(int i =0; i<m;i++){
            if(grade != score[temp] && i !=(m-1)){
                grade = score[temp];
            }
            else if(i == (m-1)){
                grade = score[temp];
                cal(grade,m,&answer);
            }
            temp++;
        }
    }
    return answer;
}