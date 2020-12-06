#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int main() {

    int N, COST;

    cin >> N >> COST;
    
    vector<int> v(N);
    vector<int> dp(COST + 1);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    
    dp[0] = 1;
    for (int i = 0; i < v.size(); i++) {
        for (int j = v[i]; j <=COST; j++) {
            dp[j] = dp[j] + dp[j - v[i]];
        }
    }
    cout << dp[COST] << endl;
    return 0;
}