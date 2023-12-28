#include <iostream>

using namespace std;

int main(){
    int hour, min, clc;
    int h_ans, m_ans;
    cin >> hour >> min >> clc;
    if((min + clc) >=60){
        m_ans = (min + clc) % 60;
        h_ans = hour + (min+ clc)/ 60;
    }else{
        m_ans = min + clc;
        h_ans = hour;
    }
    
    if(h_ans >= 24){
        h_ans -= 24;
    }
    cout << h_ans << " " << m_ans;
}