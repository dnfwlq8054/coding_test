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
	int N, a, b, M, c, d;
	int MAX = 1;
	string s;

	cin >> a >> b;
	cin >> c >> d;
	int n1 = 0, n2 = 0;

	n1 = (a * d) + (b * c);
	n2 = b * d;

	int re = gcd(n1, n2);
	cout << n1 / re << " " << n2 / re << endl;
	return 0;
}