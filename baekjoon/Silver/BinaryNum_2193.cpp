#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long> dp(N + 2);

    dp[1] = 1; dp[2] = 1;

    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 2] + dp[i - 1];

    cout << dp[N] << endl;
    return 0;
}