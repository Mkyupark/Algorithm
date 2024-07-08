import java.util.*;
import java.text.SimpleDateFormat;
import java.text.ParseException;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> answerList = new ArrayList<>();
        Map<String, Integer> termsMap = new HashMap<>();
        
        // terms 분리
        for(String term : terms){
            String[] temp = term.split(" ");
            termsMap.put(temp[0], Integer.parseInt(temp[1]));
        }
        
        // 데이터 포맷 형식을 지정
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy.MM.dd");
        Calendar cal = Calendar.getInstance();
        
        try {
            Date todayDate = simpleDateFormat.parse(today);
            
            // privacies 분리 및 계산
            for(int i = 0; i < privacies.length; i++){
                String[] privacie = privacies[i].split(" ");
                Date date = simpleDateFormat.parse(privacie[0]);
                cal.setTime(date);
                int value = termsMap.get(privacie[1]);
                cal.add(Calendar.MONTH, value);
                
                // 28일 기준 계산
                cal.add(Calendar.DAY_OF_MONTH, -1);
                
                Date expirationDate = cal.getTime();
                if(expirationDate.before(todayDate)){
                    answerList.add(i + 1);
                }
            }
        } catch (ParseException e) {
            e.printStackTrace();
        }
        
        // ArrayList를 배열로 변환
        int[] answer = answerList.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}
