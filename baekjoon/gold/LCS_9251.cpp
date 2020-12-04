#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int dp[1002][1002];


int main() {

    string s1, s2;
    cin >> s1;
    cin >> s2;

    int i, j;
    for (i = 0; i < s2.size(); i++) {
        for (j = 0; j < s1.size(); j++) {
            if (s2[i] == s1[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

        }
    }

   
    cout << dp[i][j] << endl;
    
    return 0;
}