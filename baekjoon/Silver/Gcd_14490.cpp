#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>|
#include <random>
#pragma warning(disable: 4996)

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int N, a, b, M;
	int MAX = 1;
	string s;

	cin >> s;
	int n1 = 0, n2 = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ':') {
			n1 = stoi(s.substr(0, i));
			n2 = stoi(s.substr(i + 1, s.size()));
			break;
		}
	}
	
	int re = gcd(n1, n2);
	cout << n1 / re << ":" << n2 / re << endl;
	return 0;
}