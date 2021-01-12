#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int answer = 0;
	int sum = 0;
	int MAX;
	int dp[301];
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	
	dp[0] = v[0];
	dp[1] = v[1] + v[0];
	dp[2] = max(v[0] + v[2], v[1] + v[2]);

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + v[i], v[i -1] + v[i] + dp[i - 3]);
	}
	cout << dp[N - 1] << endl;
	return 0;
}