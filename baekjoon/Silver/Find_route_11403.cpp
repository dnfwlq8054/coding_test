#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

void dfs(vector<vector<int>>& v, vector<bool>& isVisit, int idx) {

    for (int i = 0; i < v[idx].size(); i++) {
        if (v[idx][i] == 1 && !isVisit[i]) {
            isVisit[i] = true;
            dfs(v, isVisit, i);
        }
    }
}

int main() {
    int N, K;
    cin >> N;
    
    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        vector<bool> isVisit(N);

        dfs(v, isVisit, i);

        for (int i = 0; i < N; i++)
            cout << isVisit[i] << " ";
        cout << endl;
    }
    return 0;
}