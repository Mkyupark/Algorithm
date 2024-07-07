import java.util.*;

class Solution {
    
    public int solution(String[] friends, String[] gifts) {
        int answer = 0;
        int idx = friends.length;
        int [][] giftsArr = new int[idx][idx];
        int [][] giftAverage = new int [idx][3];
        // giftsArr 0 초기화
        for(int i =0; i<idx; i++){
            Arrays.fill(giftsArr[i],0);
        }
        // 주고 받은 선물 계산 배열 giftsArr
        for(int i =0; i< gifts.length; i++){
            String[] list = gifts[i].split(" ");
            int x=0; int y=0;
            // x 찾기
            for(int j =0; j< idx; j++){
                if(list[0].equals(friends[j])){
                    x= j;
                    break;
                };
            }
            // y 찾기
            for(int k =0; k< idx; k++){
                if(list[1].equals(friends[k])){
                    y=k;
                    break;
                }
            }
            giftsArr[x][y]++;
        }
        // 선물지수 계산 giftAverage
        // 1. 준 선물 계산
        for(int i =0; i< idx; i++){
            int tmp1 =0;
            int tmp2 =0;
            for(int j = 0; j<idx; j++){
                tmp1 += giftsArr[i][j]; // 준사람
                tmp2 += giftsArr[j][i]; // 받은사람
            }
            giftAverage[i][0] = tmp1;
            giftAverage[i][1] = tmp2;
            giftAverage[i][2] = tmp1 - tmp2;
        }
        
        // 다음달 받은 선물 계산
        for(int i=0; i<idx; i++){
            int tmp =0;
            for (int j =0; j<idx; j++){
                if(i != j){
                    if(giftsArr[i][j] > giftsArr[j][i]){
                        tmp++;
                    }else if (giftsArr[i][j] == giftsArr[j][i]){
                        if (giftAverage[i][2] > giftAverage[j][2]){
                            tmp++;
                        }
                    }
                }
            }
            if(answer <tmp) {
                answer = tmp;
            }
            tmp =0;
        }
        
        System.out.println(gifts.length);
        return answer;
    }
}