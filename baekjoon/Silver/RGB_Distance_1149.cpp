#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;


int main() {
    
    int N;
    cin >> N;

    vector<vector<int>> v(1010, vector<int>(3));
    vector<vector<int>> dp(1010, vector<int>(3));

    for (int i = 1; i <= N; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    for (int i = 1; i <= N; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + v[i][2];
    }
    
    cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << endl;
    return 0;
}