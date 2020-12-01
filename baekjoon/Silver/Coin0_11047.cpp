#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T, COST;
    int N, M, K;
    int X, Y;
    int answer = 10e7;

    cin >> N >> COST;
    vector<int> v(N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);

        if (COST / v[i] > 0) {
            int num = COST;
            int result = 0;
            bool flag = false;

            for (int j = i; j >= 0; j--) {
                if (num / v[j] == 0) continue;
                result += num / v[j];
                num = num % v[j];
                if (num == 0) {
                    flag = true;
                    break;
                }
            }

            if (flag)
                answer = min(answer, result);
        }
    }

    cout << answer << endl;

    return 0;
}