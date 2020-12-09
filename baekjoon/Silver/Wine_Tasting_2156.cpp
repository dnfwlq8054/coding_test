#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

int dp[10010];

int main() {
	int N, a, b;
	int answer = 0;
	cin >> N;
	
	vector<int> v(N + 3);
	for (int i = 3; i < N + 3; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 3; i < N + 3; i++) {
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);
		dp[i] = max(dp[i - 1], dp[i]);
		answer = max(answer, dp[i]);
	}

	cout << answer << endl;

	return 0;
}