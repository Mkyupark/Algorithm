import java.util.Scanner;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health; // 체력
        int bandage_sec = bandage[0]; 
        int heal = bandage[1]; 
        int plus_heal = bandage[2];
        int attack_sec = attacks[attacks.length-1][0]; // 공격이 끝나는 시간
        int ready_sec = 0; // 준비시간
        int sec=0; // 시간초
        int x = 0; // 공격의 위치
        
        while(sec<=attack_sec) {
            // 공격 시간일 경우 체력 감소
            if(sec == attacks[x][0]){
                answer-=attacks[x][1];
                ready_sec =0;
                x++;
                if(answer <= 0){
                    return -1;
                }
            } else if (answer < health) {
                answer+= heal;
                if(answer > health) {
                    answer = health;
                }
                ready_sec++;
                
                if(ready_sec == bandage_sec){
                    answer += plus_heal;
                    if(answer > health){
                        answer = health;
                    }
                    ready_sec = 0;
                }
            }
            sec++;
        }
        return answer;
    }
}