#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int cnt = attacks.size();
    int hp = health;
    int hp_sec =0;
    int temp =0;
        for(int i =1; i <= attacks[attacks.size() - 1][0]; i++){
            if(attacks[temp][0] != i){
                hp_sec++;
                if(hp_sec == bandage[0]){
                    hp+= bandage[2];
                    hp_sec=0;
                }
                hp+= bandage[1];
                if(hp > health) hp = health;
            }else if(attacks[temp][0] == i){
                hp -= attacks[temp][1];
                hp_sec = 0;
                if(hp <=0) return -1;
                temp++;
            }
        }
    answer = hp;
    return answer;
}