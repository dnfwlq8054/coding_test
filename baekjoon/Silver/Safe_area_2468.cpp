#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

using namespace std;
int answer = 1;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void bfs(vector<vector<int>>& v, int num){
	vector<vector<bool>> isVisit(v.size(), vector<bool>(v.size()));

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i][j] <= num)
				isVisit[i][j] = true;
		}
	}

	queue<pair<int, int>> q;

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (!isVisit[i][j]) {
				isVisit[i][j] = true;
				q.emplace(i, j);

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int ii = 0; ii < 4; ii++) {
						int next_x = x + dx[ii];
						int next_y = y + dy[ii];

						if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v.size() &&
							!isVisit[next_x][next_y]) {
							q.emplace(next_x, next_y);
							isVisit[next_x][next_y] = true;
						}
					}
				}
				cnt++;
			}
				
		}
	}
	answer = max(answer, cnt);
}

int main() {
	int N, a, b, M;
	int MAX = 1;
	cin >> N;
	
	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &v[i][j]);
			MAX = max(MAX, v[i][j]);
		}
		
	}

	for (int i = 1; i < MAX; i++) {
		bfs(v, i);
	}
	
	cout << answer << endl;
	return 0;
}