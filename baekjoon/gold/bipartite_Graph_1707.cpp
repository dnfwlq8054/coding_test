#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

enum {
    BLACK = 1, BLUE = 2
};

bool isCheck = true;

void dfs(vector<vector<int>>& v, vector<int>& Visit, int node, int flag) {

    for (int i = 0; i < v[node].size(); i++) {
        if (Visit[v[node][i]] != 0){
            if(Visit[v[node][i]] == Visit[node]) 
                isCheck = false;
        }
        else {
            if (flag == BLACK) {
                Visit[v[node][i]] = BLUE;
                dfs(v, Visit, v[node][i], BLUE);
            }
            else {
                Visit[v[node][i]] = BLACK;
                dfs(v, Visit, v[node][i], BLACK);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, V, E;
    cin >> T;

    for (int i = 0; i < T; i++) {

        cin >> V >> E;
        int x, y;

        vector<vector<int>> v(V + 1);
        vector<int> Visit(V + 1);

        for (int j = 0; j < E; j++) {
            cin >> x >> y;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
        }

        for (int j = 1; j <= V; j++) {
            if (Visit[j] == 0) {
                Visit[j] = BLACK;
                dfs(v, Visit, j, BLACK);
            }
            if (!isCheck)
                break;
        }

        if (isCheck)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        isCheck = true;
    }
    
    return 0;
}