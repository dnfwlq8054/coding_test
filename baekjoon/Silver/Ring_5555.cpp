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

int main() {
	int N, a, b, M;
	int answer = 0;
	int sum = 0;
	string s;
	cin >> s;
	cin >> N;

	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		temp += temp;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == s.back() && temp.substr(0, j).size() >= s.size()) {
				int n = s.size();
				int idx = j;
				bool flag = true;
				while (n--) {
					if (s[n] != temp[idx--])
						flag = false;
				}
				if (flag) {
					answer++;
					break;
				}
			}
		}
	}

	cout << answer << endl;
	return 0;
}