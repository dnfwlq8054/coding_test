#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> M >> N;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<bool>> visit(N, vector<bool>(M));
    queue<pair<int, int>> q;
    queue<int> q_cost;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &K);
            v[i][j] = K;

            if (K != 0) 
                visit[i][j] = true;
            

            if (K == 1) {
                q.emplace(i, j);
                q_cost.emplace(0);
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int cost = q_cost.front();

        q.pop(); q_cost.pop();
        answer = max(answer, cost);
        visit[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int next_x = dx[i] + x;
            int next_y = dy[i] + y;

            if (next_x > -1 && next_x < N && next_y > -1 && next_y < M
                && !visit[next_x][next_y] && v[next_x][next_y] == 0) {
                v[next_x][next_y] = 1;
                q.emplace(next_x, next_y);
                q_cost.emplace(cost + 1);
            }
        }
    }
    
    for (auto& e : visit) {
        for (auto flag : e) {
            if (!flag) {
                answer = -1;
                break;
            }
        }
    }

    cout << answer << endl;
    return 0;
}