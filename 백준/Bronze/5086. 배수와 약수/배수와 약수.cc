#include <iostream>
#include <string>

using namespace std;

int main()
{
    string c1 = "factor"; string c2 = "multiple"; string c3 = "neither";
    while(true){
        int first, second;
        cin>> first >> second;
        if(first == 0 && second == 0) break;
        if(second<first){
            if(first % second == 0) {
                cout << c2 <<endl;
            }else {
                cout << c3 <<endl;
            }
        }else{
            if(second % first ==0){
                cout <<c1 <<endl;
            }else{
                cout <<c3 <<endl;
            }
        }
    }
    return 0;
}