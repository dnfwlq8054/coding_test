#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int find_union(int n, vector<int>& cycle) {
    if (cycle[n] == n)
        return n;
    else
        return cycle[n] = find_union(cycle[n], cycle);
}

int kruskal(int _x, int _y, vector<int>& cycle) {
    int x = find_union(_x, cycle);
    int y = find_union(_y, cycle);

    if (x != y) {
        cycle[x] = y;
        return true;
    }
    return false;
}


int main() {
    
    int N, M, answer = 0;
    int x, y, cost;
    cin >> N >> M;

    vector<vector<int>> costs(M);
    vector<int> cycle(N + 1);

    for (size_t i = 1; i < cycle.size(); i++)
        cycle[i] = i;

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> cost;
        costs[i].emplace_back(x);
        costs[i].emplace_back(y);
        costs[i].emplace_back(cost);
    }

    sort(costs.begin(), costs.end(), [](auto a, auto b) {
        return a[2] < b[2];
     });

    for (auto& v : costs) {
        if (kruskal(v[0], v[1], cycle))
            answer += v[2];
    }

    cout << answer << endl;
    return 0;
}