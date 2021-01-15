#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool dfs_check[1001];
bool bfs_check[1001];

void dfs(vector<vector<int>>& v, int idx) {

    for (int i = 0; i < v[idx].size(); i++) {
        if (!dfs_check[v[idx][i]]) {
            dfs_check[v[idx][i]] = true;
            cout << v[idx][i] << " ";
            dfs(v, v[idx][i]);
        }
    }
}

void bfs(vector<vector<int>>& v, queue<int>& q) {
    
    int idx = q.front();
    q.pop();

    for (int i = 0; i < v[idx].size(); i++) {
        if (!bfs_check[v[idx][i]]) {
            bfs_check[v[idx][i]] = true;
            cout << v[idx][i] << " ";
            q.emplace(v[idx][i]);
        }
    }
    if(!q.empty())
        bfs(v, q);
}
int main() {
    int T;
    int N, M, K;
    int X, Y;
    cin >> N >> M >> K;
    vector<vector<int>> v(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        v[X].emplace_back(Y);
        v[Y].emplace_back(X);
    }

    for (auto& e : v)
        sort(e.begin(), e.end());

    cout << K << " ";
    dfs_check[K] = true;
    dfs(v, K);
    cout << endl;
    
    cout << K << " ";
    bfs_check[K] = true;
    queue<int> q;
    q.emplace(K);
    bfs(v, q);
    cout << endl;

    return 0;
}