#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visit[101][101];

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    queue<pair<int, int>> q;
    queue<int> q_cost;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &K);
            v[i][j] = K;
        }
    }
    q.emplace(0, 0);
    q_cost.emplace(1);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int cost = q_cost.front();
        q.pop(); q_cost.pop();
        
        if (x == N - 1 && y == M - 1) {
            answer = cost;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x > -1 && next_x < N && next_y > -1 && next_y < M
                && v[next_x][next_y] == 1 && !visit[next_x][next_y]) {
                visit[next_x][next_y] = true;
                q.emplace(next_x, next_y);
                q_cost.emplace(cost + 1);
            }
        }

    }
    
    cout << answer << endl;
    return 0;
}