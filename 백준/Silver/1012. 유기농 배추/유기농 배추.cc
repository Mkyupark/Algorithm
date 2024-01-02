#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int x_pos[4] = {0,0,1,-1};
int y_pos[4] = {1,-1,0,0};
void dfs(vector<vector<int>>& arr, int x, int y){
    if(x<0 || x>=arr.size() || y <0 || y>= arr[0].size() || arr[x][y] ==0){
        return;
    }
    arr[x][y] =0;
    for(int i =0; i<4; i++){
        int xx = x+x_pos[i];
        int yy = y+y_pos[i];
        dfs(arr,xx,yy);
    }
}

int main(){
    int testcase, x, y, cnt;
    
    cin >> testcase; 
    
    while(testcase--){
        // 입력
        cin >> x >> y >> cnt;
        vector<vector<int>> arr(x,vector<int>(y,0));
        int input_x, input_y;
        int answer=0;
        for(int i =0; i< cnt; i++){
            cin >> input_x >> input_y;
            arr[input_x][input_y] = 1;
        }
        
        //지렁이 갯수 구하기
        for(int i =0; i<arr.size(); i++){
            for(int j =0; j<arr[0].size(); j++){
                if(arr[i][j] ==1){
                    dfs(arr, i, j);
                    answer++;
                }
            }
        }
        cout << answer <<endl;
    }
}