#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int me, int brother){
    vector<int> visited(100001,-1);
    queue<int> q;
    
    visited[me] =0;
    q.push(me);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur ==brother){
            return visited[cur];
        }
        
        if(cur-1>=0 && visited[cur-1] == -1){
            visited[cur-1] = visited[cur] +1;
            q.push(cur-1);
        }
        
        if(cur +1 <=100000 &&visited[cur+1] == -1){
            visited[cur+1] = visited[cur] +1;
            q.push(cur+1);
        }
        
        if(cur*2 <=100000 && visited[cur*2] == -1){
            visited[cur*2] = visited[cur] +1;
            q.push(cur*2);
        }
    }
    return -1;
}

int main(){
    int me, brother;
    cin >>me >>brother;
    int answer = bfs(me, brother);
    cout << answer;
}