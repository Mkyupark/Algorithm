#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    float answer =0; int cnt = 20; string name; double credit=0;
    map<string, double> scoreMap {
        {"A+", 4.5},
        {"A0", 4.0},
        {"B+", 3.5},
        {"B0", 3.0},
        {"C+", 2.5},
        {"C0", 2.0},
        {"D+", 1.5},
        {"D0", 1.0},
        {"F", 0.0}
    };
    while(cnt--){
        getline(cin, name);
        
        vector<string> result;
        string container;
        double temp;
        istringstream iss(name);
        while(getline(iss, container, ' ')){
            result.push_back(container);
        }
        if(result[2][0] == 'P')
            continue;
        temp = stof(result[1]) * scoreMap[result[2]];
        credit+=stof(result[1]);
        answer+=temp;
    }
    if(credit != 0)
        answer /= credit;
    cout << fixed;
    cout.precision(6);
    cout << answer;
    return 0;
}
