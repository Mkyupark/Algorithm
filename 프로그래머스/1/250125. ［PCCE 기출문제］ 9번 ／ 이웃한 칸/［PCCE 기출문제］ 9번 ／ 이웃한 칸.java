import java.util.Scanner;

class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int row = board.length;
        int[] dh = {0, 1, -1, 0};
        int[] dw = {1, 0, 0, -1};
        String temp = board[h][w];
        
        for(int i =0; i< 4; i++){
            int pow_x = h+dh[i];
            int pow_y = w+dw[i];
            if( 0 <= pow_x && pow_x < row && 0<= pow_y && pow_y < row) {
                if(temp.equals(board[pow_x][pow_y])){
                    answer+=1;
                }
            }
            
        }
        return answer;
    }
}