#include <iostream>
#include <vector>
using namespace std;

int main(){
    int idx;
    cin >> idx;
    int DP[100001][3];
    
    DP[1][0] = DP[1][1] = DP [1][2] = 1; 
    for(int i =2; i<=idx; i++){
        DP[i][0] = (DP[i-1][1] + DP[i-1][2]) % 9901;
        DP[i][1] = (DP[i-1][0] + DP[i-1][2]) % 9901;
        DP[i][2] = (DP[i-1][0] + DP[i-1][1] + DP[i-1][2]) % 9901;
    }
    cout << (DP[idx][0] + DP[idx][1] + DP[idx][2]) %9901;
}