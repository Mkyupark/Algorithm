#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs (vector<int>* graph,int value, bool* check, int idx){
    check[idx] = true;
    if(!check[value]){
        dfs(graph, graph[value][0],check,value);
    }
}
int main()
{
    int cnt, size;
    cin>> cnt;
    while(cnt--){
        cin >> size;
        vector<int> graph[size +1];
        bool check[size+1];
        fill(check, check+size+1, false);
        for(int i =1; i<= size; i++){
            int v;
            cin >> v;
            graph[i].push_back(v);
        }
        int answer =0;
        for(int i =1; i<=size; i++){
            if(!check[i]){
                dfs(graph,graph[i][0],check,i);
                answer++;
            }
        }
        cout <<answer <<endl;
        
    }

    return 0;
}
