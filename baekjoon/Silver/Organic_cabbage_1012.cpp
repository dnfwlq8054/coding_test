#include <iostream>
#include <vector>

using namespace std;

int dx[3] = { 0, 0, 1 }; // 오른, 왼, 아래
int dy[3] = { 1, -1, 0 };

void bfs(vector<vector<int>>& v, int X, int Y, vector<vector<bool>>& check) {

    for (int i = Y; i < v[X].size(); i++) {
        if (v[X][i] == 0)
            break;

        if (!check[X][i] && v[X][i] == 1) {
            check[X][i] = true;
            for (int j = 0; j < 3; j++) {
                int next_X = X + dx[j];
                int next_Y = Y + dy[j];

                if (next_X < v.size() && next_Y > -1 && next_Y < v[X].size())
                    bfs(v, next_X, next_Y, check);
            }
        }
    }
    
}

int main() {
    int T;
    int N, M, K;
    int X, Y;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        vector<vector<int>> v(M + 1, vector<int>(N + 1, 0));
        vector<vector<bool>> check(M + 1, vector<bool>(N + 1, false));
        
        int answer = 0;
        
        for (int j = 0; j < K; j++) {
            cin >> X >> Y;
            v[X][Y] = 1;
        }

        for (int ii = 0; ii < M; ii++) {
            for (int jj = 0; jj < N; jj++) {
                if (v[ii][jj] == 1 && !check[ii][jj]) {
                    bfs(v, ii, jj, check);
                    answer++;
                }
            }
        }
        cout << answer << endl;

        vector<vector<int>>().swap(v);
        vector<vector<bool>>().swap(check);
    }


    return 0;
}