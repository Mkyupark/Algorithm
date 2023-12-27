#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = -1;
    int f_attack =0; int s_attack =0;  
    for(int i =0; i<3; i++){
        for (int j =0; j<3; j++){
            if(board[i][j] =='O') f_attack++;
            else if(board[i][j]=='X') s_attack++;
        }
    }
    // 선 후공 확인처리 
    if(s_attack>f_attack|| f_attack > s_attack+1) {
        answer = 0;
        return answer;
        // 공백인 경우
    }else if(s_attack == 0 && f_attack == 0){
        answer =1;
        return answer;
    }
    int tictakto =0;
    char c;
    // 동그라미가 3가 빙고인 경우 s_attack은 f_attack -1이여야 한다.
    // X가 3 빙고인 경우에는 f_attack이랑 s_attack이랑 같아야 한다.
    // 일자인 경우
    for(int i =0; i<3; i++){
        if(board[i][0] !='.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            c = board[i][0];
            tictakto++;
        }
        if(board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            c = board[0][i];
            tictakto++;
        }
    }
    // 대각선
    if(board[0][0] !='.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        c = board[0][0];
        tictakto++;
    }else if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        c= board[0][2];
        tictakto++;
    }
    // 판별
    if(tictakto >1) {
        if(tictakto ==2 && c=='O' && s_attack == f_attack-1){
            answer =1;
        }else{
            answer =0;
        }
    } else if(tictakto == 1 && c == 'O' && s_attack != f_attack -1){
        answer =0;
    } else if(tictakto ==1 && c == 'X' && s_attack != f_attack){
        answer =0;
    } else answer =1;
    return answer;
}