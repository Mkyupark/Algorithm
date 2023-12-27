#include <iostream>
#include <string>

using namespace std;

int checkTrue (string s){
    int init =0;
    int size = s.length() - 1;
    
    while(init <= size){
        if(s[init] != s[size]){
            return 0;
        }
        init++; size--;
    }
    return 1;
}

int main()
{
    string temp;
    cin>> temp;
    cout << checkTrue(temp);
}
