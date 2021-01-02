#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#pragma warning(disable: 4996)

using namespace std;

string s = "I";


int main() {
	int N, a, b, M;
	int answer = 0;
	string s;

	cin >> N;
	cin >> M;
	cin >> s;

	int cnt = 0;
	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			cnt++;
			if (cnt == N) {
				cnt--;
				answer++;
			}
			i++;
		}
		else
			cnt = 0;
	}

	cout << answer << endl;
	
	return 0;
}