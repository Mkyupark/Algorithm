#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> answer;

void bfs(vector<string> maps, vector<pair<int,int>>& notX){
    queue<pair<int,int>> q;
    int ant = 0;
    q.push(make_pair(notX[0].first, notX[0].second));
    int checkBox[101][101] = {0};
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        ant = ant + maps[temp.first][temp.second] -'0';
        checkBox[temp.first][temp.second] =1;
        notX.erase(remove_if(notX.begin(), notX.end(), [temp](const pair<int, int>& p) {
            return p == temp;
        }), notX.end());
        int x = temp.first;
        int y = temp.second;
        for(int i=0; i<4; i++){
            if(i ==0 && x-1 >= 0 && maps[x-1][y] != 'X' && checkBox[x-1][y] == 0){
                q.push(make_pair(x-1, y));
                checkBox[x-1][y] =1;
            } else if (i ==1 && x+1< maps.size() && maps[x+1][y] != 'X'&& checkBox[x+1][y] == 0){
                q.push(make_pair(x+1,y));
                checkBox[x+1][y] =1;
            } else if(i ==2 && y-1 >=0 && maps[x][y-1] != 'X' && checkBox[x][y-1] ==0){
                q.push(make_pair(x,y-1));
                checkBox[x][y-1] =1;
            } else if(i==3 && y+1 < maps[0].size() && maps[x][y+1] !='X'&& checkBox[x][y+1] ==0){
                q.push(make_pair(x,y+1));
                checkBox[x][y+1] =1;
            }
        }
    }
    answer.push_back(ant);
}

vector<int> solution(vector<string> maps) {
    
    vector<pair<int, int>> notX;
    for(int i =0; i<maps.size(); i++){
        for(int j =0; j< maps[0].size(); j++){
            if(maps[i][j] != 'X'){
                notX.push_back(make_pair(i,j));
            }
        }
    }
    answer.clear();
    if(notX.empty()) {
        answer.push_back(-1);
        return answer;
    };
    while(!notX.empty()){
        bfs(maps, notX);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
