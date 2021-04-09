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

    for (int idx = 1; idx < flag; idx++) {
        queue<Edge> q;
        vector<vector<bool>> isFlag_Visit(N, vector<bool>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (v[i][j] == idx)
                    q.emplace(i, j, 0);
            }
        }

        while (!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            int cost = q.front().cost;
            q.pop();

            if (v[x][y] != 0 && v[x][y] != idx) {
                answer = min(answer, cost - 1);
                break;
            }

            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (next_x > -1 && next_x < N && next_y > -1 && next_y < N
                    && v[next_x][next_y] != idx && !isFlag_Visit[next_x][next_y]) {
                    isFlag_Visit[next_x][next_y] = true;
                    q.emplace(next_x, next_y, cost + 1);
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}