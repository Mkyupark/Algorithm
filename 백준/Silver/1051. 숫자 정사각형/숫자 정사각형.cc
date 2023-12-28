#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    //입력
    int x, y;
    int len;
    char arr[51][51] = {-1};
    cin >> x >> y;
    for(int i =0; i< x; i++){
        for(int j =0; j<y; j++){
            cin >> arr[i][j];
        }
    }
    // 풀이
    int answer =1;
    len = min(x, y);
    for(int i =1; i<len; i++){
        for(int j =0; j<x -i; j++){
            for(int k = 0; k <y-i; k++){
                if(arr[j][k] == arr[j+i][k] && arr[j][k] == arr[j][k+i] && arr[j][k] == arr[j+i][k+i])
                    answer = i+1;
            }
        }
    }
    answer = answer* answer;
    cout <<answer;
    
}