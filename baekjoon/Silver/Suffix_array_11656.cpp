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
	int answer = 0;

	string s;
	cin >> s;
	vector<string> v;

	for (int i = 0; i < s.size(); i++) {
		string temp = s.substr(i, s.size());
		v.emplace_back(temp);
	}

	sort(v.begin(), v.end());

	for (auto s : v)
		cout << s << endl;

	return 0;
}