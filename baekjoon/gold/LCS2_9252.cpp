#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<string>> dp(1003, vector<string>(1003));
    int index = 0;
    
    string s1, s2;
    cin >> s1 >> s2;
    
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];   
            else{
                if(dp[i - 1][j].size() >= dp[i][j - 1].size())
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    
    cout << dp[s1.size()][s2.size()].size() << endl;
    cout << dp[s1.size()][s2.size()] << endl;
    
    return 0;
}