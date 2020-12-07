#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dp[501][501];

int dfs(vector<vector<int>>& v, int x, int y) {

    if (x == v.size() - 1 && y == v[x].size() - 1)
        return 1;

    if (dp[x][y] != -1)
        return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int next_x = dx[i] + x;
        int next_y = dy[i] + y;

        if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v[x].size()) {
            if (v[x][y] > v[next_x][next_y]) {
                dp[x][y] += dfs(v, next_x, next_y);
            }
        }
    }
    return dp[x][y];
}

int main() {

    int N, M;

    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &v[i][j]);
            dp[i][j] = -1;
        }
    }

    dfs(v, 0, 0);

    cout << dp[0][0] << endl;

    return 0;
}