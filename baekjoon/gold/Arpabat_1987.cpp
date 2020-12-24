#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <random>
#pragma warning(disable: 4996)

using namespace std;
int answer = 1;

bool arpabat[26];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


void dfs(vector<vector<char>>& v, int x, int y, int num){
	
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v[x].size()
			&& !arpabat[v[next_x][next_y] - 'A']) {
			arpabat[v[next_x][next_y] - 'A'] = true;
			dfs(v, next_x, next_y, num + 1);
			arpabat[v[next_x][next_y] - 'A'] = false;
		}
	}

	answer = max(num, answer);
}

int main() {
	int N, a, b, M;
	int MAX = 1;
	cin >> N >> M;
	
	vector<vector<char>> v(N, vector<char>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	}

	arpabat[v[0][0] - 'A'] = true;
	dfs(v, 0, 0, 1);

	cout << answer << endl;
	return 0;
}