#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

struct Tomato {
    int x = 0;
    int y = 0;
    int h = 0;
    int cost = 0;
    Tomato() {}
    Tomato(int _x, int _y, int _h, int _cost) : x(_x), y(_y), h(_h), cost(_cost) {}
};

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    int cost = 0;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> v(N, vector<vector<int>>(M, vector<int>(H, 0)));
    vector<vector<vector<bool>>> isVisit(N, vector<vector<bool>>(M, vector<bool>(H, 0)));
    queue<Tomato> q;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> K;
                v[i][j][h] = K;
                if (K != 0)
                    isVisit[i][j][h] = true;
                if (K == 1)
                    q.emplace(i, j, h, 0);
            }
        }
    }
    
    while (!q.empty()) {
        Tomato t = q.front();
        q.pop();
        cost = t.cost;

        for (int i = 0; i < 6; i++) {
            int x = dx[i] + t.x;
            int y = dy[i] + t.y;
            int h = dh[i] + t.h;

            if (x > -1 && x < N && y > -1 && y < M && h > -1 && h < H
                && !isVisit[x][y][h] && v[x][y][h] != -1) {
                isVisit[x][y][h] = true;
                v[x][y][h] = 1;
                q.emplace(x, y, h, cost + 1);
            }
        }
    }
    
    answer = cost;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (v[i][j][h] == 0) {
                    answer = -1;
                    break;
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}