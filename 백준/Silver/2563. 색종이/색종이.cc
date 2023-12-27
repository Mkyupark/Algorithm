#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> whitepaper(100, vector<int>(100, 0));
    int cnt, row, col, answer =0;
    cin >> cnt;
    while (cnt--) {
        cin >> row >> col;
        for (int i = row; i < row + 10; i++) {
            for (int j = col; j < col + 10; j++) {
                whitepaper[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            answer += whitepaper[i][j];
        }
    }
    cout << answer;
    return 0;
}