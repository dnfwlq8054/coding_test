#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>|
#include <random>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int answer = 1;

	cin >> N;
	vector<pair<int, int>> v;
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end(), [](auto a, auto b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
		});

	int num = v[0].second;
	for (int i = 1; i < N; i++) {
		if (v[i].first >= num) {
			answer++;
			num = v[i].second;
		}
	}

	cout << answer << endl;
	return 0;
}