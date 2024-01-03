#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int x_pos[4] = {0,0, 1, -1};
int y_pos[4] = {1,-1,0,0};


void bfs(vector<vector<int>>& ice, vector<vector<int>>& visited, int start_x, int start_y){
    int x = ice.size();
    int y = ice[0].size();
    // 방문 & 임시 저장 배열
    vector<vector<int>> temp (x, vector<int> (y,0));
    queue<pair<int,int>> q;
    // 시작지점 찾기
    
    q.push({start_x, start_y});
    visited[start_x][start_y] =1;
    while(!q.empty()){
        int s_x = q.front().first;
        int s_y = q.front().second;
        q.pop();
        int cnt =0;
        for(int i =0; i< 4; i++){
            int xx = s_x + x_pos[i];
            int yy = s_y + y_pos[i];
            if(xx >=0 && xx<x && yy>=0 && yy<y){
                if(visited[xx][yy] != 1){
                    q.push(make_pair(xx,yy));
                    visited[xx][yy] = 1;
                }
                if(ice[xx][yy] ==0){
                    cnt++;
                }
            }
        }
        if((ice[s_x][s_y] - cnt) >0){
            temp[s_x][s_y] = ice[s_x][s_y] - cnt;
        }else{
            temp[s_x][s_y] = 0;
        }
    }
    // ice 배열 변환
    for(int i =0; i<x; i++){
        for(int j=0; j<y; j++){
            ice[i][j] = temp[i][j];
        }
    }
}
void dfs(vector<vector<int>>& ice, vector<vector<int>>& visited, int x, int y){
    if(x<0 || x>= ice.size() || y<0 || y>= ice[0].size() || visited[x][y] == 1 || ice[x][y] == 0)
        return;
    visited[x][y] =1;
    for(int i =0; i<4; i++){
        int xx = x + x_pos[i];
        int yy = y + y_pos[i];
        dfs(ice, visited, xx, yy);
    }
}

int main(){
    // 입력
    int x, y;
    cin >> x >> y;
    vector<vector<int>> ice(x, vector<int>(y));
    for(int i = 0; i<x; i++){
        for(int j =0; j<y; j++){
            cin >> ice[i][j];
        }
    }
    // 결과
    int answer =0;
    while(true){
        vector<vector<int>> visited(x, vector<int>(y,0));
        int start_x = -1, start_y =-1;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (ice[i][j] != 0) {
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
            if (start_x != -1) break;
        }

        if (start_x == -1) {
            cout << 0;
            return 0;
        }
        // ice 변환
        bfs(ice, visited, start_x, start_y);
        answer++;
        // 조각 났는지 판별
        int piece =0;
        visited.assign(x, vector<int>(y, 0));
        for(int i =0; i<x; i++){
            for(int j =0; j<y; j++){
                if(ice[i][j] != 0 && visited[i][j] != 1){
                    dfs(ice, visited,i,j);
                    piece++;
                    if(piece >1) break;
                }
                if (piece > 1) break;
            }
        }
        if (piece > 1) {
            cout << answer;
            return 0;
        }
    }
}
