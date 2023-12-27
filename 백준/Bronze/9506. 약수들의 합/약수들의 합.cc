#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    while(true){
        vector<int> v;
        int answer =0;
        cin >>num;
        if(num == -1) break;
        for(int i =1; i <= num/2; i++){
           if(num % i == 0){
                v.push_back(i);
                answer+= i;
            }
        }
        if(answer == num) {
            cout << answer << " = "; 
            for(int i =0; i< v.size() -1; i++){
                cout << v[i] <<" + ";
            }
            cout << v[v.size()-1] <<endl;
        }else{
            cout <<num << " is NOT perfect." <<endl;
        }
        
    }
}