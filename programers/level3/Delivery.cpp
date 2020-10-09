#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[51];
int c_cost[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> v(N + 1);
    queue<pair<int, int>> q;

    fill_n(c_cost, 51, 99999999);

    for(auto& e : road){
            v[e[0]].emplace_back(e[1], e[2]);
            v[e[1]].emplace_back(e[0], e[2]);
    }

    q.emplace(1, 0);
    while(!q.empty()){
        int next = q.front().first;
        int cost = q.front().second;
        q.pop();
        if(c_cost[next] != 99999999 && c_cost[next] != cost) continue;

        if(cost <= K && !check[next]) {
            check[next] = true;
            answer++;
        }

        for(auto& p : v[next]){
            int n = p.first;
            if(p.second + cost < c_cost[n]) c_cost[n] = p.second + cost;
            q.emplace(n, p.second + cost);
        }
    }
    return answer;
}