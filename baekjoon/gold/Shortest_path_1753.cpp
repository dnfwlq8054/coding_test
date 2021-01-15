#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

struct cmp {
    bool operator()(pair<int, int>  t, pair<int, int> u) {
        return t.second > u.second;
    }
};


int INF = 10e9;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int start;
    string S;

    cin >> N >> M;
    vector<vector<pair<int, int>>> v(N + 1);
    vector<int> cost(N + 1);
    
    for (int i = 0; i <= N; i++)
        cost[i] = INF;

    cin >> start;
    cost[start] = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &X, &Y, &K);
        v[X].emplace_back(Y, K);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.emplace(start, 0);

    while (!q.empty()) {
        int idx = q.top().first;
        int cnt = q.top().second;
        q.pop();

        for (int i = 0; i < v[idx].size(); i++) {
            int y = v[idx][i].first;
            int n = v[idx][i].second;


            if (cost[y] > n + cost[idx] ) {
                cost[y] = n + cost[idx];
                q.emplace(y, cost[y]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (cost[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", cost[i]);
    }
    return 0;
}