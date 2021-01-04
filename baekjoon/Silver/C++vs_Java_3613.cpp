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
	string s;
	cin >> s;


	if (s[0] == '_' || s.back() == '_' || (s[0] >= 'A' && s[0] <= 'Z')) {
		cout << "Error!" << endl;
		return 0;
	}
		
	bool c = false, java = false, err = false;
	int cnt = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_') {
			c = true;
			cnt++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
			java = true;
		else
			cnt = 0;

		if (cnt == 2) {
			cout << "Error!" << endl;
			return 0;
		}
			
	}
	if (c == true && java == true) {
		cout << "Error!" << endl;
		return 0;
	}
	else if (c == false && java == false) {
		cout << s << endl;
		return 0;
	}

	string temp = "";
	if (c) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '_') {
				i++;
				temp += (s[i] - 32);
			}else
				temp += s[i];
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				temp += '_';
				temp += (s[i] + 32);
			}
			else
				temp += s[i];
		}
	}

	cout << temp << endl;
	return 0;
}