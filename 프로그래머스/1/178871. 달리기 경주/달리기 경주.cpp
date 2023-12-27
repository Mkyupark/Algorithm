#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string>answer;
    map<int, string> m1;
    map<string,int> m2;
    for(int iter= 0; iter<players.size(); iter++){
        m1[iter] = players[iter];
        m2[players[iter]] = iter;
    }
    for(int iter =0; iter<callings.size(); iter++){
        int rank = m2[callings[iter]];
        string player = m1[rank-1]; //poe
        m2[m1[rank]] = rank-1; // kai = 3
        m2[player] = rank; // poe = 4
        m1[rank-1] = callings[iter]; // 3 = kai
        m1[rank] = player;
    }
    for(auto c : m1) answer.push_back(c.second);
    
    
    return answer;
}