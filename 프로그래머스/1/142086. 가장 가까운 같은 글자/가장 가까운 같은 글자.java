import java.util.*;

class Solution {
    public ArrayList <Integer> solution(String s) {
        ArrayList <Integer> answerList = new ArrayList<>();
        int[] answer = {};
        HashMap<Character, Integer> map = new HashMap<Character, Integer> ();
        
        for(int i =0; i< s.length(); i++){
            if(!map.containsKey(s.charAt(i))){
                map.put(s.charAt(i), i);
                // 여기서 answer 값 추가하는거 생성 -1 추가 하면됨
                answerList.add(-1);
            }else {
                int value = map.get(s.charAt(i));
                int temp = i - value; // answer 갑싱ㅁ
                map.put(s.charAt(i),i);
                answerList.add(temp);
            }
        }
        return answerList;
    }
}