#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>

#pragma warning(disable: 4996)

using namespace std;

void dfs(vector<char>& v, int idx, int N, string s) {
	if (s.size() == N) {
		int j = 0, m = 0;
		for (auto c : s) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				j++;
			else
				m++;
		}
		if(j > 0 && m > 1)
			cout << s << endl;

		return;
	}
	
	for (int i = idx; i < v.size(); i++) {
		s += v[i];
		dfs(v, i + 1, N, s);
		s.pop_back();
	}
}


int main() {
	int N, a, b, M, c, d;
	int x, y;
	int answer = 0;

	string s, temp;
	cin >> N >> M;
	vector<char> v(M);

	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	dfs(v, 0, N, "");
	
	return 0;
}