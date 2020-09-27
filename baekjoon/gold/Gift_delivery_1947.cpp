#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long int> dp(1000003);
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = i * (dp[i - 1] + dp[i - 2]) % 1000000000;
    }

    cout << dp[N - 1] << endl;
    return 0;
}
