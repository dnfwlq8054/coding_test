#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void){

    int a, b, cnt = 0;
    cin >> a >> b;
    vector<vector<char>> v(a, vector<char>(b));
    vector<vector<bool>> isVisit(a, vector<bool>(b));
    queue<pair<int, int>> water_queue;
    queue<pair<int, int>> biber;
    char c;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> c;
            v[i][j] = c;
            if (c == '*')
                water_queue.emplace(i, j);
            else if (c == 'S')
                biber.emplace(i, j);
        }
    }

    while (!biber.empty()) {
        int len = water_queue.size();        
        
        for(int idx = 0; idx < len; idx++){           //물 채우기
            int x = water_queue.front().first;
            int y = water_queue.front().second;
            water_queue.pop();

            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (next_x > -1 && next_x < a && next_y > -1 && next_y < b &&
                    v[next_x][next_y] == '.') {
                    v[next_x][next_y] = '*';
                    water_queue.emplace(next_x, next_y);
                }
            }
        }
        
        int len2 = biber.size();

        for (int idx = 0; idx < len2; idx++) {
            int x = biber.front().first;
            int y = biber.front().second;
            biber.pop();

            if (v[x][y] == 'D') {
                cout << cnt << endl;
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (next_x > -1 && next_x < a && next_y > -1 && next_y < b && !isVisit[next_x][next_y] &&
                    v[next_x][next_y] != '*' && v[next_x][next_y] != 'X') {
                    isVisit[next_x][next_y] = true;
                    biber.emplace(next_x, next_y);
                }
            }
        }
        cnt++;
    }

    cout << "KAKTUS" << endl;

    return 0;

}

