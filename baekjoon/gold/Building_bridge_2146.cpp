#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool isVisit[101][101];

struct Edge {
    int x;
    int y;
    int cost;

    Edge(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost){}
};

struct cmp {
    bool operator() (const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    }
};

priority_queue<Edge, vector<Edge>, cmp> pq[101];

void mapCheck(vector<vector<int>>& v, vector<vector<bool>>& isFlag_Visit, int x, int y, int flag) {
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x > -1 && next_x < N && next_y > -1 && next_y < N
            && !isVisit[next_x][next_y]) {
            if (v[next_x][next_y] != 0) {
                v[next_x][next_y] = flag;
                isVisit[next_x][next_y] = true;
                mapCheck(v, isFlag_Visit, next_x, next_y, flag);
            }
            else {
                if (!isFlag_Visit[next_x][next_y]) {
                    isFlag_Visit[next_x][next_y] = true;
                    pq[flag].emplace(next_x, next_y, 1);
                }
            }
        }
    }
}

int main(){

    int answer = 99999;
    cin >> N;
    vector<vector<int>> v(N + 1, vector<int>(N + 1));
    int flag = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isVisit[i][j] && v[i][j] != 0) {
                isVisit[i][j] = true;
                vector<vector<bool>> isFlag_Visit(N + 1, vector<bool>(N + 1));
                v[i][j] = flag;
                mapCheck(v, isFlag_Visit, i, j, flag++);
            }
        }
    }

    for (int i = 1; i < flag; i++) {
        priority_queue<Edge, vector<Edge>, cmp> cp_pq = pq[i];
        vector<vector<int>> currentCost(N + 1, vector<int>(N + 1));

        while (!cp_pq.empty()) {
            Edge edge = cp_pq.top();
            cp_pq.pop();

            int x = edge.x;
            int y = edge.y;
            int cost = edge.cost;

            if (v[x][y] != 0 && v[x][y] != i) {
                answer = min(answer, cost - 1);
                break;
            }

            for (int j = 0; j < 4; j++) {
                int next_x = x + dx[j];
                int next_y = y + dy[j];

                if (next_x > -1 && next_x < N && next_y > -1 && next_y < N
                    && v[next_x][next_y] != i) {
                    if (currentCost[next_x][next_y] == 0) {
                        currentCost[next_x][next_y] = cost + 1;
                        cp_pq.emplace(next_x, next_y, cost + 1);
                    }
                    else if (currentCost[next_x][next_y] > cost + 1) {
                        currentCost[next_x][next_y] = cost + 1;
                        cp_pq.emplace(next_x, next_y, cost + 1);
                    }
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}