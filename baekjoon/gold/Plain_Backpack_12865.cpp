#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int start;
    string S;
    

    cin >> N >> M;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    vector<int> w(N + 1), v(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - w[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][M] << endl;
    return 0;

}