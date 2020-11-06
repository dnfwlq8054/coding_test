#include <iostream>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int isCost[100010];

int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 999999;

    cin >> N >> K;
    queue<pair<int, int>> q;
    q.emplace(N, 0);

    while (!q.empty()) {
        int locate = q.front().first;
        int cost = q.front().second;
        q.pop();

        if (isCost[locate] != 0 && isCost[locate] < cost)
            continue;

        if (locate == K) {
            answer = isCost[locate];
            break;
        }

        int x_1 = locate - 1;
        int x_2 = locate + 1;
        int x_3 = locate * 2;


        if (0 <= x_1) {
            if (isCost[x_1] == 0) {
                isCost[x_1] = cost + 1;
                q.emplace(x_1, cost + 1);
            }
            else {
                if (isCost[x_1] > cost + 1) {
                    isCost[x_1] = cost + 1;
                    q.emplace(x_1, cost + 1);
                }
            }
        }

        if (x_2 <= K) {
            if (isCost[x_2] == 0) {
                isCost[x_2] = cost + 1;
                q.emplace(x_2, cost + 1);
            }
            else {
                if (isCost[x_2] > cost + 1) {
                    isCost[x_2] = cost + 1;
                    q.emplace(x_2, cost + 1);
                }
            }
        }

        if (x_3 <= K + 1) {
            if (isCost[x_3] == 0) {
                isCost[x_3] = cost;
                q.emplace(x_3, cost);
            }
            else {
                if (isCost[x_3] > cost) {
                    isCost[x_3] = cost;
                    q.emplace(x_3, cost);
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}