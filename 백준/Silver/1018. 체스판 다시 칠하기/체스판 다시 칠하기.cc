#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string whiteBoard[8]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string blackBoard[8] ={
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};
int cntwhiteBoard(vector<vector<char>>board, int x_start, int x_end, int y_start, int y_end){
    int cnt =0;
    for(int i =x_start; i<x_end; i++){
        for(int j =y_start; j<y_end; j++){
            if(board[i][j] == whiteBoard[i-x_start][j-y_start])
                cnt++;
        }
    }
    return cnt;
}
int cntblackBoard(vector<vector<char>>board, int x_start, int x_end, int y_start, int y_end){
    int cnt =0;
    for(int i =x_start; i<x_end; i++){
        for(int j =y_start; j<y_end; j++){
            if(board[i][j] == blackBoard[i-x_start][j-y_start])
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    //입력
    int x,y;
    cin>>x>>y;
    vector<vector<char>> board(x,vector<char>(y));
    for(int i =0; i<x; i++){
        for(int j =0; j<y; j++){
            cin >> board[i][j];
        }
    }
    //풀이
    int answer =32;
    for(int i =0; i+8<=x; i++){
        for(int j =0; j+8<=y; j++){
            int tmp = min(cntblackBoard(board, i, i+8, j, j+8), cntwhiteBoard(board, i, i+8, j, j+8));
            if(tmp <answer) answer = tmp;
        }
    }
    cout <<answer;
    
    return 0;
}
