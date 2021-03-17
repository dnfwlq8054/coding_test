#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, maxNum = 0;
    int dp[1001];
    
    cin >> N;
    vector<int> P(N + 1);
    
    for(int i = 1; i <= N; i++){
        cin >> P[i];
        dp[i] = 0;
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            dp[j] = max(P[i] + dp[j - i], dp[j]);
        }
    }
    
    cout << dp[N] << endl;
    
    return 0;
}