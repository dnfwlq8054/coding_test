#include <iostream>
#include <vector>

using namespace std;

bool check[101];
int answer = 0;

void dfs(vector<vector<int>>& v, int idx) {
    for (int i = 0; i < v[idx].size(); i++) {
        if (!check[v[idx][i]]) {
            check[v[idx][i]] = true;
            answer++;
            dfs(v, v[idx][i]);
        }
    }
}


int main() {
    int T;
    int N, M, K;
    int X, Y;

    cin >> N;
    vector<vector<int>> v(N + 1);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> X >> Y;
        v[X].emplace_back(Y);
        v[Y].emplace_back(X);
    }
    check[1] = true;
    dfs(v, 1);
    
    cout << answer << endl;
    return 0;
}