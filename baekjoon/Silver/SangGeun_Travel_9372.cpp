#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int cost = 0;

void dfs(vector<vector<int>>& v, vector<bool>& isVisit, int idx) {
    
    for (int i = 0; i < v[idx].size(); i++) {
        if (!isVisit[v[idx][i]]) {
            cost++;
            isVisit[v[idx][i]] = true;
            dfs(v, isVisit, v[idx][i]);
        }
    }
}

int main() {
    int T, COST;
    int N, M, K;
    int X, Y;

    cin >> T;
    vector<int> answer;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        vector<vector<int>> v(N + 1);
        vector<bool> isVisit(N + 1);

        for(int j = 0; j < M; j++){
            cin >> X >> Y;
            v[X].emplace_back(Y);
            v[Y].emplace_back(X);
        }
        isVisit[0] = true;
        
        for (int j = 1; j <= N; j++) {
            if (v[j].size() > 0 && !isVisit[j]) {
                isVisit[j] = true;
                dfs(v, isVisit, j);
                //cost++;
            }
        }
        answer.emplace_back(cost);
        cost = 0;
    }
    for (auto n : answer)
        cout << n << endl;

    return 0;
}