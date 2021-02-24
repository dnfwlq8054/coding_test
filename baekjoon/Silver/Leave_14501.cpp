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

int dfs(vector<pair<int, int>>& v, int idx, int cost) {
	int result = 0;

	if (idx > v.size() - 1) {
		return cost;
	}

	for (int i = idx; i < v.size(); i++) {
		result = max(result, dfs(v, i + v[i].first, v[i].second + cost));
	}

	return result;
}

int main() {
	int N, a, b, M, c, d, T, K, W;
	int x, y, node_cost;
	int flag = 1;
	int answer = 0;

	cin >> N;
	vector<pair<int, int>> v(1);

	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		if (a + i > N + 1)
			v.emplace_back(99999, 0);
		else
			v.emplace_back(a, b);
	}

	answer = dfs(v, 1, 0);

	cout << answer << endl;

	return 0;
}