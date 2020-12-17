#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	cin >> N;
	vector<int> v(N);
	vector<int> dp(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	int answer = v[0];

	for (int i = 0; i < N; i++) {
		dp[i + 1] = max(v[i] + dp[i], v[i]);
		answer = max(answer, dp[i + 1]);
	}

	cout << answer << endl;
	return 0;
}