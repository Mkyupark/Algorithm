class Solution {
    
    public int countDivision(int num){
        int answer = 0;
        for(int i = 1; i * i <= num; i++){
            if(num % i == 0){
                answer++;
                if(i != num / i){ // 제곱근이 아닌 경우 짝수인 약수도 추가
                    answer++;
                }
            }
        }
        return answer;
    }
    
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i =1; i<= number; i++){
            int temp = countDivision(i);
            if(temp > limit){
                answer += power;
            }else{
                answer +=temp;
            }
        }
        return answer;
    }
}