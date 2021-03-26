#include <iostream>
#include <cstdio>

#pragma warning(disable: 4996)

using namespace std;

long MOD = 1e9 + 9;
long long dp[100001][4];

int main() {
    int N, K;
    scanf("%d", &N);

    dp[1][1] = dp[2][2] = dp[3][3] = 1;

    for (int i = 2; i < 100001; i++) {
        if (i - 1 > 0) {
            dp[i][1] += (dp[i - 1][2] + dp[i - 1][3]);
            dp[i][1] %= MOD;
        }
        if (i - 2 > 0) {
            dp[i][2] += (dp[i - 2][1] + dp[i - 2][3]);
            dp[i][2] %= MOD;
        }
        if (i - 3 > 0) {
            dp[i][3] += (dp[i - 3][1] + dp[i - 3][2]);
            dp[i][3] %= MOD;
        }
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        cout << (dp[K][1] + dp[K][2] + dp[K][3]) % MOD << endl;
    }

    return 0;
}