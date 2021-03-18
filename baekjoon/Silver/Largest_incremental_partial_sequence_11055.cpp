#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, A;
    int dp[1003], input[1003];
    int MAX = 0;
    cin >> N;

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> input[i];
        for (int j = 0; j < i; j++) {
            if (input[i] > input[j])
                dp[i] = max(dp[i], dp[j]);
        }

        dp[i] += input[i];
        MAX = max(MAX, dp[i]);
    }
    cout << MAX << endl;
    return 0;
}