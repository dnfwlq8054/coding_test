#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#pragma warning(disable: 4996)

int dx[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };// 위, 아래, 왼쪽, 오른쪽, 1시, 5시, 7시, 11시
int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

using namespace std;

void dfs(vector<vector<int>>& v, vector<vector<int>>& isVisit, int x, int y) {
	
	for (int i = 0; i < 8; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v[x].size() 
			&& v[next_x][next_y] != 0 && !isVisit[next_x][next_y]) {

			isVisit[next_x][next_y] = true;
			dfs(v, isVisit, next_x, next_y);
		}
	}
}

int main() {
	int N, a, b, M;
	
	while (true) {
		cin >> N >> M;
		int answer = 0;
		if (N == 0 && M == 0)
			break;

		vector<vector<int>> v(M, vector<int>(N));
		vector<vector<int>> isVisit(M, vector<int>(N));

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &v[i][j]);
			}
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisit[i][j] && v[i][j] != 0) {
					dfs(v, isVisit, i, j);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
	
	return 0;
}