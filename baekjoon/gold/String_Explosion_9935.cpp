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
	string answer = "";
	string s, bumb;

	cin >> s >> bumb;

	for (int i = 0; i < s.size(); i++) {
		answer += s[i];
		if (answer.back() == bumb.back() && answer.size() >= bumb.size()) {
			string temp = answer.substr(answer.size() - bumb.size(), answer.size());
			
			if (temp == bumb) {
				int N = bumb.size();
				while (N--) answer.pop_back();
			}
		}
	}
	
	if (answer.size() == 0)
		cout << "FRULA" << endl;
	else
		cout << answer << endl;

	return 0;
}