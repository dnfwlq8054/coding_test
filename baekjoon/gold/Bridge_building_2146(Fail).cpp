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

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool isVisit[103][103];
queue<pair<int, int>> q[103];
queue<int> cost_q[103];

void map_FlagChange(vector<vector<int>>& v, int x, int y, int flag){
	queue<pair<int, int>> q_flag;
	q_flag.emplace(x, y);

	while (!q_flag.empty()) {
		int _x = q_flag.front().first;
		int _y = q_flag.front().second;
		q_flag.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = _x + dx[i];
			int next_y = _y + dy[i];

			if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v.size() &&
				v[next_x][next_y] == 1 && !isVisit[next_x][next_y]) {
				v[next_x][next_y] = flag;
				isVisit[next_x][next_y] = true;
				q[flag].emplace(next_x, next_y);
				cost_q[flag].emplace(0);
				q_flag.emplace(next_x, next_y);
			}
		}
	}
}

int island_cost(vector<vector<int>>& v, int flag) {
	
	vector<vector<bool>> isVisit2(103, vector<bool>(103));

	while (!q[flag].empty()) {
		int x = q[flag].front().first;
		int y = q[flag].front().second;
		int cost = cost_q[flag].front();
		q[flag].pop(); cost_q[flag].pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v.size() &&
				v[next_x][next_y] != flag && !isVisit2[next_x][next_y]) {

				if (v[next_x][next_y] != 0)
					return cost;
				
				isVisit2[next_x][next_y] = true;
				q[flag].emplace(next_x, next_y);
				cost_q[flag].emplace(cost + 1);
			}
		}
	}

	return 0;
}

int main() {
	int N, a, b, M, c, d, T, K, W;
	int x, y, node_cost;
	int flag = 1;
	int answer = 999999;

	cin >> N;
	vector<vector<int>> v(N);

	for (int i = 0; i < N; i++) {		//input
		for (int j = 0; j < N; j++) {
			scanf("%1d", &K);
			v[i].emplace_back(K);
		}
	}

	for (int i = 0; i < N; i++) {		//change island flag
		for (int j = 0; j < N; j++) {
			if (v[i][j] != 0 && !isVisit[i][j]) {
				v[i][j] = flag;
				isVisit[i][j] = true;
				q[flag].emplace(i, j);
				cost_q[flag].emplace(0);
				map_FlagChange(v, i, j, flag++);
			}
		}
	}

	for (int i = 1; i < flag; i++) {
		if(!q[i].empty())
			answer = min(answer, island_cost(v, i));
	}

	cout << answer << endl;

	return 0;
}