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

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N;

void bfs(vector<vector<char>>& v, vector<vector<bool>>& isVisit, int x, int y, char RGB, bool& isCheck) {
    
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (isCheck) {
            if (next_x > -1 && next_x < N && next_y > -1 && next_y < N &&
                !isVisit[next_x][next_y] && v[next_x][next_y] == RGB) {
                isVisit[next_x][next_y] = true;
                bfs(v, isVisit, next_x, next_y, RGB, isCheck);
            }
        }
        else {
            if (next_x > -1 && next_x < N && next_y > -1 && next_y < N &&
                !isVisit[next_x][next_y]) {

                if (RGB == 'R' || RGB == 'G') {
                    if (v[next_x][next_y] == 'R' || v[next_x][next_y] == 'G') {
                        isVisit[next_x][next_y] = true;
                        bfs(v, isVisit, next_x, next_y, v[next_x][next_y], isCheck);
                    }
                }
                else {
                    if (v[next_x][next_y] == RGB) {
                        isVisit[next_x][next_y] = true;
                        bfs(v, isVisit, next_x, next_y, RGB, isCheck);
                    }
                }
            }
        }
    }
}

int main() {

    int answer_1 = 0, answer_2 = 0;
    cin >> N;
    vector<vector<char>> v(N, vector<char>(N));
    vector<vector<bool>> isVisit_O(N, vector<bool>(N));
    vector<vector<bool>> isVisit_X(N, vector<bool>(N));
    bool Color = true, Color_ness = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!isVisit_O[i][j]) {
                isVisit_O[i][j] = true;
                bfs(v, isVisit_O, i, j, v[i][j], Color);
                answer_1++;
            }
            if (!isVisit_X[i][j]) {
                isVisit_X[i][j] = true;
                bfs(v, isVisit_X, i, j, v[i][j], Color_ness);
                answer_2++;
            }
        }
    }

    cout << answer_1 << " " << answer_2 << endl;
    return 0;
}