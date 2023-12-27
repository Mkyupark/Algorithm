#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> scoreMap;
    for(auto iter= 0; iter < name.size(); iter++){
        scoreMap[name[iter]] = yearning[iter];
    }
    for(int i =0; i<photo.size(); i++){
        int score=0;
        for(int j =0; j<photo[i].size(); j++){
            score+=scoreMap[photo[i][j]];
        }
        answer.push_back(score);
    }
    return answer;
}