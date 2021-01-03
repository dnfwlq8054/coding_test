#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int answer = 0;
	string s;
	map<string, int> m;
	vector<string> v;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		cin >> s;
		m[s]++;
		if (m[s] > 1)
			v.emplace_back(s);
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto e : v)
		cout << e << endl;
	
	return 0;
}