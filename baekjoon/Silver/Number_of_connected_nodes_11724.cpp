#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

void dfs(vector<vector<int>>& v, vector<bool>& isVisit, int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (!isVisit[v[idx][i]]) {
			isVisit[v[idx][i]] = true;
			dfs(v, isVisit, v[idx][i]);
		}
	}
}

int main() {
	int N, a, b, M;
	
	cin >> N >> M;
	int answer = 0;

	vector<vector<int>> v(N + 1);
	vector<bool> isVisit(N + 1);
	#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;

void dfs(vector<vector<int>>& v, vector<bool>& isVisit, int idx) {
	for (int i = 0; i < v[idx].size(); i++) {
		if (!isVisit[v[idx][i]]) {
			isVisit[v[idx][i]] = true;
			dfs(v, isVisit, v[idx][i]);
		}
	}
}

int main() {
	int N, a, b, M;
	
	cin >> N >> M;
	int answer = 0;

	vector<vector<int>> v(N + 1);
	vector<bool> isVisit(N + 1);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].emplace_back(y);
	}

	for (int i = 1; i <= N; i++) {
		if (!isVisit[i]) {
			dfs(v, isVisit, i);
			answer++;
		}
	}
	cout << answer << endl;
	
	
	return 0;
}
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].emplace_back(y);
	}

	for (int i = 1; i <= N; i++) {
		if (!isVisit[i]) {
			dfs(v, isVisit, i);
			answer++;
		}
	}
	cout << answer << endl;
	
	
	return 0;
}