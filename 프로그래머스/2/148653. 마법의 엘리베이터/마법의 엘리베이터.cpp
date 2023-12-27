#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0, temp =0;
    string s = to_string(storey);
    for(int i =(s.size()-1); i>=0; i--){
       if(s[i]>'5'){
           answer = answer + 10 - s[i] +'0';
           cout <<i << " " <<answer <<endl;
           if(s[i-1] != '9'){
               s[i-1] +=1;
           }
           else{
               temp++;
           }
           if(i == 0){
               answer++;
           }
       }
        else if(s[i] == '5'){
            if(s[i-1] <='4'){
                answer = answer + s[i] -'0'; 
                cout <<i << " " <<answer <<endl;
            }
            else{
                answer = answer + 10 - s[i] +'0';
                cout <<i << " " <<answer <<endl;
                if(s[i-1] != '9'){
                    s[i-1] +=1;
                }
                else{
                    temp++;
                }
            }
        }
        else{
            answer = answer + s[i] -'0';
            cout <<i << " " <<answer <<endl;
        }
    }
    answer-=temp;
    cout <<"결과" << answer;
    return answer;
}