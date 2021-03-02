#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <cmath>

#pragma warning(disable: 4996)

using namespace std;

int main(){
    int N, K, two = 0, five = 0;

    int dp[1001][1001];
    
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (i == j || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
            }
        }
    }
    cout << dp[N][K] << endl;

    return 0;
}