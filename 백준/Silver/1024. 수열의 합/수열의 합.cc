#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int num, cnt;
    vector<int> answer;
    cin >>num >>cnt;
    
    while(cnt <=100){
        if(cnt %2 ==0){
            int tmp = cnt/2;
            if(num%tmp ==0 && (num/tmp) %2 ==1){
                int tmp2 = num/tmp;
                answer.push_back(tmp2/2);
                answer.push_back(tmp2/2+1);
                for(int i=1; i< tmp; i++){
                  answer.push_back(tmp2/2 -i);
                  answer.push_back(tmp2/2+1 +i);
                }
                break;
            }
            cnt++;
        }else{
            if(num%cnt ==0){
                int tmp = num/cnt;
                answer.push_back(tmp);
                for(int i =1; i<= cnt/2; i++){
                    answer.push_back(tmp-i);
                    answer.push_back(tmp+i);
                }
                break;
            }
            cnt++;
        }
    }
    sort(answer.begin(),answer.end());
    if(answer[0]<0 || answer.empty()){
        cout <<-1;
    }else{
        for(int i =0; i<answer.size();i++){
            cout <<answer[i] << " ";
        }
    }

}