#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M, c, d, T, K, W;
	int x, y, node_cost;
	int flag = 1;
	int answer = 0;

	vector<vector<int>> dp(31, vector<int>(31));

	for (int i = 1; i < 31; i++)
		dp[1][i] = i;

	for (int i = 2; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			for (int k = 1; k < j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << dp[N][M] << endl;
	}

	return 0;
}