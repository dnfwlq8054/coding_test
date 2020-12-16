#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int MAX = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	vector<int> dp(12);
	
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	for(int i = 0; i < v.size(); i++)
		cout << dp[v[i]] << endl;
	return 0;
}