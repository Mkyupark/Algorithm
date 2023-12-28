#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b){
    return a>b;
}

int main(){
    vector<int> arr1;
    vector<int> arr2;
    int cnt,tmp;
    cin >> cnt;
    for(int i =0; i<cnt; i++){
        cin >>tmp;
        arr1.push_back(tmp);
    }
    for(int i =0; i<cnt; i++){
        cin>> tmp;
        arr2.push_back(tmp);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), compare);

    int answer =0;
    for(int i =0; i<cnt; i++){
        answer += arr1[i] * arr2[i];
    }
    cout <<answer;
}