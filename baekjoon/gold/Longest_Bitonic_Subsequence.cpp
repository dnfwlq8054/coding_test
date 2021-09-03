#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

int MAX = 1002;

int main(){
    int N;
    cin >>N;
    
    int arr[MAX];
    int dp[MAX];    
    int dp_r[MAX];  

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
 
    for (int i = N; i >= 1; i--) {
        dp_r[i] = 1;
        
        for (int j = N; j >= i; j--) {
            if (arr[i] > arr[j] && dp_r[j] + 1 > dp_r[i]) {
                dp_r[i] = dp_r[j] + 1;
            }
        }
    }
 
    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (result < dp[i] + dp_r[i] - 1) 
            result = dp[i] + dp_r[i] - 1;
    }
    
    cout << result << endl;

    return 0;
}