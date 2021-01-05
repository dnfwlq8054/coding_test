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
	string s;
	getline(cin, s);
	
	int idx = 0;
	string e = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			string temp = "";
			while (s[i] != '>')
				temp += s[i++];
			answer += temp + ">";
		}
		else
			e += s[i];
		
		if (i + 1 < s.size() && s[i + 1] == '<'){
			reverse(e.begin(), e.end());
			answer += e;
			e = "";
		}
		else if (s[i] == ' ') {
			e.pop_back();
			reverse(e.begin(), e.end());
			answer += e + " ";
			e = "";
		}
	}

	reverse(e.begin(), e.end());
	answer += e;


	cout << answer << endl;
	return 0;
}