#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    int answer = 0;
    string str1, str2;
    cin >> str1;
    cin >> str2;
    vector<vector<int>> dp(4005, vector<int>(4005, 0));

    for (size_t i = 1; i <= str1.size(); i++) {
        for (size_t j = 1; j <= str2.size(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}