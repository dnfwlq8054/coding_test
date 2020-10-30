#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)


using namespace std;

bool visit[26][26];
int dx[4] = { -1, 1, 0, 0 };    //위 아래 오른쪽 왼쪽
int dy[4] = { 0, 0, 1, -1 };

int dfs(vector<vector<int>>& v, int x, int y) {

    if (v[x][y] == 0 || visit[x][y])
        return 0;

    int sum = 1;

    visit[x][y] = true;

    for (int j = 0; j < 4; j++) {
        int next_x = x + dx[j];
        int next_y = y + dy[j];

        if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v.size()) {
            sum += dfs(v, next_x, next_y);
        }
    }

    return sum;
}

int main() {
    int T;
    int N, M, K;
    int X, Y;
    
    cin >> N;
    vector<vector<int>> v(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &M);
            v[i].emplace_back(M);
        }
    }
    
    vector<int> home_count;
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 1 && !visit[i][j]) {
                count++;
                home_count.emplace_back(dfs(v, i, j));
            }
        }
    }

    sort(home_count.begin(), home_count.end());

    cout << count << endl;
    for (auto n : home_count) 
        cout << n << endl;
    
    return 0;
}