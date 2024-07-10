import java.util.*;

class Solution {
    public List<Integer> solution(int k, int[] score) {
        List<Integer> answer = new ArrayList<>();
        List<Integer> king = new ArrayList<>();
        
        for(int i =0; i< score.length; i++){
            king.add(score[i]);
            Collections.sort(king, Collections.reverseOrder());
            if(king.size() <k){
                answer.add(king.get(i));
            }else if(king.size() == k){
                answer.add(king.get(k-1));
            }else{
                king.remove(k);
                answer.add(king.get(k-1));
            }
        }
        
        
        return answer;
    }
}