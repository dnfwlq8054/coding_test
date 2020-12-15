#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

int bfs(vector<vector<pair<int, int>>>& v, int start, int dis) {
	vector<int> cost(v.size());
	for (int i = 0; i < cost.size(); i++)
		cost[i] = 16000000;
	priority_queue<pair<int, int>> q;

	q.emplace(start, 0);
	cost[start] = 0;
	while (!q.empty()) {
		int locate = q.top().first;
		int locate_cost = q.top().second;
		q.pop();

		if (cost[locate] < locate_cost)
			continue;

		for (int i = 0; i < v[locate].size(); i++) {
			int cur = v[locate][i].first;
			int cur_cost = v[locate][i].second;

			if (cost[cur] == 0) {
				cost[cur] = cur_cost;
				q.emplace(cur, cur_cost);
			}
			else if (cost[cur] > cur_cost + locate_cost) {
				cost[cur] = cur_cost + locate_cost;
				q.emplace(cur, cost[cur]);
			}
		}
	}
	if (cost[dis] == 0)
		return 160000001;
	else
		return cost[dis];
}

int main() {
	int N, a, b, M;
	int answer1 = 0;
	int answer2 = 0;

	cin >> N >> M;

	vector<vector<pair<int, int>>> v(N + 1);

	for (int i = 0; i < M; i++) {
		int x = 0, y = 0, cost = 0;

		scanf("%d %d %d", &x, &y, &cost);
		v[x].emplace_back(y, cost);
		v[y].emplace_back(x, cost);
	}

	cin >> a >> b;
	answer1 += bfs(v, 1, a) + bfs(v, a, b) + bfs(v, b, N);
	answer2 += bfs(v, 1, b) + bfs(v, b, a) + bfs(v, a, N);

	if (answer1 > 160000000 && answer2 > 160000000)
		cout << -1 << endl;
	else
		cout << min(answer1, answer2) << endl;

	return 0;
}