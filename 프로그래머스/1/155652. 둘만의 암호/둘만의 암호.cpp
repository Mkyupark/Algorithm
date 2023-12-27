#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    sort(skip.begin(), skip.end());
    for(int i =0; i< s.length(); i++){
        char alp = s[i];
        for(int j =0; j<index; j++){
            alp++;
            if(alp>'z'){
                alp='a';
            }
             while (skip.find(alp) != string::npos) {
                alp++;
                if (alp > 'z') {
                    alp = 'a';
                }
            }
//             for(int k =0; k<skip.length(); k++){
//                 if(alp == skip[k] && alp != 'z'){
//                     alp++;
//                 }
//                 else if (alp == skip[k] && alp == 'z'){
//                     alp='a';

//                 }

//             }
        }

        answer.push_back(alp);
    }
    
    return answer;
}
    