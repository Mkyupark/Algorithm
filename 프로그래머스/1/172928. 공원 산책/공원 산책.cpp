#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    map<char,int> direct ={{'E',0}, {'S',1}, {'W',2}, {'N',3}};
    int dx[4] ={1, 0, -1, 0};
    int dy[4] ={0, 1, 0, -1};
    //'S'위치 찾기
    for(int i =0; i< park.size(); i++){
        for(int j =0; j<park[i].size(); j++){
            if(park[i][j] =='S') {
                answer.push_back(j);
                answer.push_back(i);
            }
        }
    }
    // 길찾기
    for(auto route : routes){
        int x = answer[0], y=answer[1]; //현재 위치
        int check =1;
        cout << "answer : " <<answer[0] <<" " <<answer[1]<<endl;

        for(int i=0; i<route[2] -'0'; i++){
            int idx = direct[route[0]];
            x+=dx[idx]; 
            y+=dy[idx];
            if(x>=park[y].size() || x<0 || y<0 || y>=park.size()){
                check=0;
                cout <<"dump check: " << endl;
                break;
            }
            if(park[y][x] == 'X') {
                check=0;
                cout <<"check: " <<endl;;
                break;
            }
        }
        if(check){
            answer[0] = x, answer[1]=y;
        }
    }
    int temp = answer[0];
    answer[0] = answer[1];
    answer[1] = temp;
    return answer;
}