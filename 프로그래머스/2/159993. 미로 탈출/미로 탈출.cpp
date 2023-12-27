#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int answer =0;

struct graphPosAndDepth{
    int x;
    int y;
    int depth;
    graphPosAndDepth(int x, int y, int depth) : x(x), y(y), depth(depth){}
};

void dfs(pair<int,int> start, pair<int,int> target, vector<string> maps){
    queue<graphPosAndDepth> q;
    q.push(graphPosAndDepth(start.first, start.second, 0));
    graphPosAndDepth temp = q.front();
        // 방문 확인
    vector<vector<int>> checkBox(maps.size(), vector<int>(maps[0].size(), 0));
    checkBox[start.first][start.second] = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.x == target.first && temp.y == target.second){
            answer += temp.depth;
            break;
        }
        int i = temp.x; 
        int j = temp.y;
        for(int cnt =0; cnt<4; cnt++){
            // x-1
            if(cnt ==0 && i-1 >=0 &&maps[i-1][j] != 'X' && checkBox[i-1][j] == 0){
                q.push(graphPosAndDepth(i-1,j,temp.depth+1));
                checkBox[i-1][j] =1;
            // x+1
            }else if(cnt ==1 && i+1 <maps.size() && maps[i+1][j] != 'X' && checkBox[i+1][j] == 0){
                q.push(graphPosAndDepth(i+1,j,temp.depth+1));
                checkBox[i+1][j] =1;
            //y-1
            }else if(cnt ==2 && j-1>=0 && maps[i][j-1] != 'X' && checkBox[i][j-1] == 0){
                q.push(graphPosAndDepth(i,j-1,temp.depth+1));
                checkBox[i][j-1] =1;
            // y+1
            }else if(cnt ==3 && j+1< maps[0].size() && maps[i][j+1] != 'X' && checkBox[i][j+1] == 0){
                q.push(graphPosAndDepth(i,j+1,temp.depth+1));
                checkBox[i][j+1] =1;
            }
        }
    }
    if(temp.x != target.first || temp.y != target.second){
        answer = -1;
    } 
}

int solution(vector<string> maps) {
    char c;
    pair<int,int> start;
    pair<int,int> end;
    pair<int,int> lever;
    for(int i =0; i<maps.size(); i++){
        for(int j =0; j<maps[0].size(); j++){
            c = maps[i][j];
            if(c == 'S'){
                start={i,j};
            }else if(c == 'L'){
                lever = {i, j};
            }else if(c =='E'){
                end = {i, j};
            }
        }
    }
    answer=0;
    dfs(start, lever, maps);
    if(answer != -1){
        dfs(lever, end, maps);        
    }

    return answer;
}