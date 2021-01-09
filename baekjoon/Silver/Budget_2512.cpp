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
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
	}
	
	cin >> MAX;
	sort(v.rbegin(), v.rend());
	int left = 0;
	int right = MAX;

	if (sum <= MAX) {
		cout << v[0] << endl;
		return 0;
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int n = sum;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > mid) 
				n = n - v[i] + mid;
			else
				break;
		}
		if (MAX >= n) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << answer << endl;
	return 0;
}