#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

bool isVisit[1001][1001][2];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct Tank {
    int x = 0;
    int y = 0;
    int cost = 0;
    int isShot = 0;
    Tank() {}
    Tank(int _x, int _y, int _cost, bool _isShot) : x(_x), y(_y), cost(_cost), isShot(_isShot) {}
};

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = -1;
    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &v[i][j]);
        }
    }

    queue<Tank> q;
    q.emplace(Tank());

    while (!q.empty()) {
        Tank t = q.front();
        q.pop();
        int cost = t.cost;
        int isShot = t.isShot;

        if (t.x == N - 1 && t.y == M - 1) {
            answer = cost + 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int x = dx[i] + t.x;
            int y = dy[i] + t.y;

            if (x > -1 && x < N && y > -1 && y < M) {
                if (isVisit[x][y][isShot]) continue;

                if (v[x][y] == 0) {
                    isVisit[x][y][isShot] = true;
                    q.emplace(x, y, cost + 1, isShot);
                }
                if (v[x][y] == 1 && isShot == 0) {
                    isVisit[x][y][1] = true;
                    q.emplace(x, y, cost + 1, 1);
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}