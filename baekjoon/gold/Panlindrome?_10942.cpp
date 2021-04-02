#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>

#pragma warning(disable: 4996)

using namespace std;

int main() {

    int N, answer = 0;
    scanf("%d", &N);
    
    vector<int> v(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    v.emplace_back(-1);
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));

    for (int i = 1; i <= N; i++) {
        int s_1 = i, e_1 = i;
        int s_2 = i - 1, e_2 = i;
        bool flag_1 = true, flag_2 = true;
        while (true) {
            if (flag_1) {
                if (v[s_1] == v[e_1])
                    dp[s_1--][e_1++] = 1;
                else
                    flag_1 = false;
            }
            if (flag_2) {
                if (v[s_2] == v[e_2])
                    dp[s_2--][e_2++] = 1;
                else
                    flag_2 = false;
            }

            if (flag_1 == false && flag_2 == false)
                break;
        }
    }

    int M, s, e;
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }

    return 0;
}