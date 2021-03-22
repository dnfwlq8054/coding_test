#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
 
    int dp[10001];
    int arr[N];
    dp[0] = 0;
 
    for(int i = 0; i < N; i++)
        cin >> arr[i];
 
 
    for(int i = 1; i < 10001; i++)
        dp[i] = 99999;
 
 
    for(int i = 0; i < N; i++){
        for(int j = arr[i]; j <= M; j++){
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
    }
 
    if(dp[M] == 99999)
        printf("-1\n");
    else
        printf("%d\n", dp[M]);
 
    return 0;
}