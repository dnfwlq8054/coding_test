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
	int MAX;
	string s;


	while (true) {
		string temp = "";
		getline(std::cin, s);
		if (s[0] == '.') break;
		bool flag = true;
		for (char c : s) {
			if (c == '[' || c == '(') temp += c;
			else if (c == ']'){
				if (temp.size() == 0 || temp.back() != '[') {
					flag = false;
					break;
				}else
					temp.pop_back();
			}
			else if (c == ')'){
				if (temp.size() == 0 || temp.back() != '(') {
					flag = false;
					break;
				}
				else
					temp.pop_back();
			}

		}
		if (flag && temp.size() == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}