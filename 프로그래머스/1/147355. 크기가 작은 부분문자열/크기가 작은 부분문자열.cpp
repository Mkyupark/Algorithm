#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_size = p.size(); int t_size = t.size();
    int minus = t_size - p_size;
    for (int i =0; i< minus+1; i++){
        string temp;
        temp = t.substr(i,p_size);

        cout <<temp << " " << p <<endl;
      
        if(stol(temp) <= stol(p)){
            answer++;
        }


    }
    return answer;
}

