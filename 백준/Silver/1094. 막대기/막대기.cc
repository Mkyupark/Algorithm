#include <iostream>
#include <vector>

using namespace std;
int main(){
    int c;
    int stick = 64;
    vector<int> answer;
    int ans =0;
    cin >> c;
    while(true){
        int k = stick/2;
        if(stick > c){
            stick = k;
        }else if(stick < c){
            answer.push_back(k);
            c -= stick;
        }else {
            answer.push_back(k);
            break;
        }
    }
    cout << answer.size();
    
}