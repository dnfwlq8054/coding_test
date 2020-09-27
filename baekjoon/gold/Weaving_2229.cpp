#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(1001), dp(1001);
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
        int Max = 0, Min = 10000;

        for (int j = i; j > 0; j--)
        {
            Max = max(Max, v[j]);
            Min = min(Min, v[j]);
            dp[i] = max(dp[i], Max - Min + dp[j - 1]);
        }
    }
    printf("%d", dp[N]);
    return 0;
}
