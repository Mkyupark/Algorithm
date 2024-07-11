import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        char alp = s.charAt(0);
        int first = 1;
        int second = 0;
        if(s.length() == 1){
            return 1;
        }
        for(int i =1; i<s.length(); i++){
            if(alp != s.charAt(i)){
                ++second;
            }else if (alp == s.charAt(i)){
                ++first;
            }
            
            if(first == second && i < s.length()-1){
                alp = s.charAt(i+1);
                if(i<s.length() -2){
                    i++;   
                }
                first = 1;
                second =0;
                answer++;
            }else if (i == s.length()-1){
                answer++;
            }
        }        
        return answer;
    }
}