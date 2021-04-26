#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


int main(){
    int N, M;
    cin >> M >> N;
    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<int>> cost(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &v[i][j]);
            cost[i][j] = 99999;
        }
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    cost[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = dx[i] + x;
            int next_y = dy[i] + y;

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;

            if (v[next_x][next_y] == 1) {
                if (cost[x][y] + 1 < cost[next_x][next_y]) {
                    cost[next_x][next_y] = cost[x][y] + 1;
                    q.emplace(next_x, next_y);
                }
            }
            else if(v[next_x][next_y] == 0){
                if (cost[x][y] < cost[next_x][next_y]) {
                    cost[next_x][next_y] = cost[x][y];
                    q.emplace(next_x, next_y);
                }
            }
        }
    }

    cout << cost[N - 1][M - 1] << endl;

    return 0;

}

