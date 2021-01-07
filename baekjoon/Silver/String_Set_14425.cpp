#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <unordered_map>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int answer = 0;
	cin >> N >> M;
	unordered_map<string, int> m;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s] = 1;
	}
	
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (m.find(s) != m.end()) {
			answer++;
		}
	}

	cout << answer << endl;
	return 0;
}