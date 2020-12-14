#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

int main() {
	int N, a, b, M;
	int answer = 0;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		if (num == 0) {
			v.pop_back();
		}
		else
			v.emplace_back(num);
	}
	
	for (auto n : v)
		answer += n;

	cout << answer << endl;
	return 0;
}