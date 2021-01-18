#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M, K;
	int answer = 0;

	cin >> N;

	multiset<int> s;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		s.emplace(n);
	}

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	int len = s.size() - 1;
	
	for (int i = 0; i < len; i++) {
		int n = *s.begin();
		s.erase(s.begin());
		n += *s.begin();
		s.erase(s.begin());
		s.emplace(n);
		answer += n;
	}


	cout << answer << endl;

	return 0;
}