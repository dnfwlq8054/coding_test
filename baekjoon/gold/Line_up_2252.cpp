#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>

#pragma warning(disable: 4996)

int indegree[32001];

using namespace std;

int main() {
	int N, a, b, M, c, d;
	int x, y;
	int answer = 0;

	cin >> N >> M;
	vector<vector<int>> v(N + 1);
	queue<int> q;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;	
		v[x].emplace_back(y);
		indegree[y]++;
	}

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.emplace(i);
	}

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		cout << num << " ";

		for (int i = 0; i < v[num].size(); i++) {
			indegree[v[num][i]]--;
			if (indegree[v[num][i]] == 0)
				q.emplace(v[num][i]);
		}
	}

	return 0;
}