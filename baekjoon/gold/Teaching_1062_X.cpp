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
int answer = 0;

void dfs(int idx, int k, vector<string>& v, int count, vector<bool> isCheck) {
	if (idx == v.size())
		return;

	vector<bool> cp_isCheck = isCheck;
	int cp_k = k;
	for (int i = 4; i < v[idx].size() - 4; i++) {
		if (!isCheck[v[idx][i] - 'a']) {
			isCheck[v[idx][i] - 'a'] = true;
			k--;
		}
	}
	if (k >= 0) {
		answer = max(answer, count + 1);
		dfs(idx + 1, k, v, count + 1, isCheck);
	}
	else {
		dfs(idx + 1, cp_k, v, count, cp_isCheck);
	}
}

int main() {
	int N, a, b, M, K;
	int sum = 0;
	vector<bool> isCheck(26);
	isCheck['a' - 'a'] = true;
	isCheck['n' - 'a'] = true;
	isCheck['t' - 'a'] = true;
	isCheck['i' - 'a'] = true;
	isCheck['c' - 'a'] = true;


	cin >> N >> K;
	vector<string> v(N);

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	K -= 5;
	for (int i = 0; i < v.size(); i++) {
		int count = 0;
		vector<bool> cp_isCheck = isCheck;

		for (int j = 4; j < v[i].size() - 4; j++) {
			if (!cp_isCheck[v[i][j] - 'a']) {
				count++;
				cp_isCheck[v[i][j] - 'a'] = true;
			}
		}
		if(K - count >= 0)
			dfs(0, K - count, v, 0, cp_isCheck);
	}

	cout << answer << endl;

	return 0;
}