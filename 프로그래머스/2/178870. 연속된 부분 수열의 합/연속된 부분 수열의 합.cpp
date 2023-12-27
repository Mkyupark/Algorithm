#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(const pair<int,int> a, const pair<int,int> b){
    if(a.second == b.second) {
        return a.first <b.first;
    }
    return a.second < b.second;
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int begin =0; int end =0; int sum =sequence[0];
    while(begin <= end && end <= sequence.size()){
        if(sum > k){
            sum -= sequence[begin++];
        }else if(sum < k){
            sum+= sequence[++end];
        }else if (sum == k){
            if(answer.size() == 2){
                if((answer[1] - answer[0]) >end-begin){
                    answer.erase(answer.begin(),answer.begin() + 2);
                    answer.push_back(begin);
                    answer.push_back(end);
                } 
            }else if (answer.size() == 0){
                    answer.push_back(begin);
                    answer.push_back(end);
            }
            sum -= sequence[begin++];
        }
    }

    return answer;
}