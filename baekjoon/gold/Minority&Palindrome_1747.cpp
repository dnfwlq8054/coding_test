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

#define MAX 1030002

bool arr[MAX];

bool even_check(string s) {
	int right = s.size() / 2;
	int left = right - 1;

	while (left >= 0 && right < s.size()) {
		if (s[left--] != s[right++])
			return false;
	}

	return true;
}

bool odd_check(string s) {
	int right = s.size() / 2;
	int left = s.size() / 2;

	while (left >= 0 && right < s.size()) {
		if (s[left--] != s[right++])
			return false;
	}

	return true;
}
int main() {
	int N, a, b, M;
	int answer = 0;
	int sum = 0;
	cin >> N;
	string s;
	vector<string> v;
	arr[1] = true;

	for (int i = 2; i < MAX; i++) {
		if (arr[i] == false) {
			for (int j = i * 2; j < MAX; j += i) {
				arr[j] = true;
			}
		}
	}

	for (int i = 0; i < MAX; i++) {
		if (arr[i] == false && i >= N)
			v.emplace_back(to_string(i));
	}

	for (auto num : v){
		if (num.size() % 2 == 0) {
			if (even_check(num)) {
				cout << num << endl;
				break;
			}
		}
		else {
			if (odd_check(num)) {
				cout << num << endl;
				break;
			}
		}
	}
	
	return 0;
}