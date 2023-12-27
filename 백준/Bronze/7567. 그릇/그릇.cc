#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s; char c;
    cin>>s;
    c = s[0]; int answer =10;
    for(int i =1; i< s.size(); i++){
        if(c != s[i]) {
            c = s[i]; answer+=10;
        }
        else answer+=5;
    }
    cout << answer;
}
