#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int x_pos[4] = {0, 0, 1, -1};
int y_pos[4] = {1, -1, 0, 0};

void bfs(vector<vector<int>>& ice, vector<vector<int>>& visited, int x, int y) {
    int x_size = ice.size();
    int y_size = ice[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty()) {
        int s_x = q.front().first;
        int s_y = q.front().second;
        q.pop();
        int cnt = 0;

        for (int i = 0; i < 4; i++) {
            int xx = s_x + x_pos[i];
            int yy = s_y + y_pos[i];

            if (xx >= 0 && xx < x_size && yy >= 0 && yy < y_size) {
                if (!visited[xx][yy]) {
                    if (ice[xx][yy] == 0) {
                        cnt++;
                    } else {
                        q.push({xx, yy});
                        visited[xx][yy] = 1;
                    }
                }
            }
        }

        if ((ice[s_x][s_y] - cnt) > 0) {
            ice[s_x][s_y] -= cnt;
        } else {
            ice[s_x][s_y] = 0;
        }
    }
}

void dfs(vector<vector<int>>& ice, vector<vector<int>>& visited, int x, int y) {
    int x_size = ice.size();
    int y_size = ice[0].size();

    if (x < 0 || x >= x_size || y < 0 || y >= y_size || visited[x][y] == 1 || ice[x][y] == 0)
        return;

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int xx = x + x_pos[i];
        int yy = y + y_pos[i];
        dfs(ice, visited, xx, yy);
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<int>> ice(x, vector<int>(y));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> ice[i][j];
        }
    }

    int answer = 0;
    while (true) {
        vector<vector<int>> visited(x, vector<int>(y, 0));
        int piece = 0;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (ice[i][j] != 0 && !visited[i][j]) {
                    dfs(ice, visited, i, j);
                    piece++;
                    if (piece > 1) break;
                }
            }
            if (piece > 1) break;
        }

        if (piece > 1) {
            cout << answer;
            return 0;
        }

        visited.assign(x, vector<int>(y, 0));
        int start_x = -1, start_y = -1;

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (ice[i][j] != 0) {
                    start_x = i;
                    start_y = j;
                    break;
                }
            }
            if (start_x != -1) break;
        }

        if (start_x == -1) {
            cout << 0;
            return 0;
        }

        bfs(ice, visited, start_x, start_y);
        answer++;
    }

    return 0;
}
