#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int x_pos[4] = {0,0,1,-1};
int y_pos[4] = {1,-1,0,0};

void dfs(vector<vector<int>>& area, int x, int y, int& ans){
    if(x<0 || x>=area.size() || y<0 || y>= area[0].size() || area[x][y] ==1)
        return;
    area[x][y] = 1;
    ans++;
    for(int i =0; i<4; i++){
        int xx = x+x_pos[i];
        int yy = y+y_pos[i];
        dfs(area, xx, yy, ans);
    }
}


int main(){
    //입력
    int M, N, rect_cnt;
    cin>> M >> N >> rect_cnt;
    vector<vector<int>> area(M, vector<int>(N,0));
    while(rect_cnt--){
        int rect1_x, rect1_y, rect2_x, rect2_y;
        cin >> rect1_x >> rect1_y >> rect2_x >> rect2_y;
        
        for(int i =rect1_x; i<rect2_x; i++){
            for(int j =rect1_y; j<rect2_y; j++){
                area[j][i] = 1;
            }
        }
    }
    // 정답 구하기
    vector<int> answer;
    int ans =0;
    for(int i =0; i<M; i++){
        for(int j =0; j<N; j++){
            if(area[i][j] == 0){
                dfs(area, i, j, ans);
                answer.push_back(ans);
                ans =0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() <<endl;
    for(int i =0; i< answer.size(); i++){
        cout <<answer[i]<<" ";
    }
}