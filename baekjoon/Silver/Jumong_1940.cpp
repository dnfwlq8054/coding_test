#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <deque>

#pragma warning(disable: 4996)

using namespace std;


int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;

    cin >> N >> M;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        if (v[i] == -1)
            continue;

        for (int j = i + 1; j < N; j++) {
            if (v[j] != -1 && v[i] + v[j] == M) {
                answer++;
                v[j] = -1;
                break;
            }
        }
    }
   
    cout << answer << endl;
    return 0;
}
