#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    int alp[26] = {0};
    
    for (int i = 0; i < keymap.size(); i++){
        for(int j =0; j <keymap[i].size(); j++){
            int k = (keymap[i][j] - 'A');
            if(alp[k]==0 || (alp[k] >j) ){
                alp[k] =j+1;
            }
        }
    }
    for (int i =0; i <targets.size(); i++){
        int anw = 0;
        for(int j =0; j<targets[i].size(); j++){
            
            int k = (targets[i][j] - 'A');
            if(alp[k] != 0){
                anw+=alp[k];
            }
            else{
                anw = -1;
                break;
            }
        }
        answer.push_back(anw);
    }
    return answer;
}

