#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int visit[100010];
bool isCheck[100010];

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> N >> K;
    queue<pair<int, int>> q;
    q.emplace(N, 0);
    visit[N] = -1;
    isCheck[N] = true;
    
    while (!q.empty()) {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (locate == K) {
            answer = cost;
            break;
        }

        int x_1 = locate - 1;
        int x_2 = locate + 1;
        int x_3 = locate * 2;


        if (0 <= x_1 && !isCheck[x_1]) {
            isCheck[x_1] = true;
            visit[x_1] = locate;
            q.emplace(x_1, cost + 1);
        }

        if (x_2 <= K && !isCheck[x_2]) {
            isCheck[x_2] = true;
            visit[x_2] = locate;
            q.emplace(x_2, cost + 1);
        }

        if (x_3 <= K + 1 && !isCheck[x_3]) {
            isCheck[x_3] = true;
            visit[x_3] = locate;
            q.emplace(x_3, cost + 1);
        }
    }
    cout << answer << endl;
    int idx = K;
    vector<int> v = { K };

    while (visit[idx] != -1) {
        v.emplace_back(visit[idx]);
        idx = visit[idx];
    }
    for (auto itr = v.rbegin(); itr != v.rend(); itr++)
        cout << *itr << " ";
    return 0;
}