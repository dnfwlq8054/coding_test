#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M, c, d;
	int x, y;
	int answer = 0;

	string s, temp;
	getline(cin, s);
	getline(cin, temp);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == temp[0] && s.size() - i >= temp.size()) {
			bool flag = true;
			int ii = i;
			for (int j = 0; j < temp.size(); j++) {
				if (s[ii++] != temp[j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				answer++;
				i = ii - 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}