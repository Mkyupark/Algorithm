#include <iostream>
#include <queue>

using namespace std;

int bfs(int me, int brother) {
    vector<int> visited(100001, -1);  // 방문 여부 및 거리를 저장하는 배열
    queue<int> q;

    visited[me] = 0;
    q.push(me);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == brother) {
            return visited[cur];
        }

        if (cur - 1 >= 0 && visited[cur - 1] == -1) {
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }

        if (cur + 1 <= 100000 && visited[cur + 1] == -1) {
            visited[cur + 1] = visited[cur] + 1;
            q.push(cur + 1);
        }

        if (2 * cur <= 100000 && visited[2 * cur] == -1) {
            visited[2 * cur] = visited[cur] + 1;
            q.push(2 * cur);
        }
    }

    return -1;  // 찾을 수 없는 경우
}

int main() {
    int me, brother;
    cin >> me >> brother;

    int result = bfs(me, brother);
    
    cout << result << endl;

    return 0;
}
