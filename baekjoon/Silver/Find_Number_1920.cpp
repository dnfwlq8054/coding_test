#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0); 
	int N, M, num;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A.begin(), A.end());
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> num;
		int start = 0, end = N - 1;
		bool flag = false;

		while (start <= end) {
			int mid = (start + end) / 2;
			if (A[mid] == num) {
				printf("1\n");
				flag = true;
				break;
			}
			else {
				if (A[mid] < num) start = mid + 1;
				else end = mid - 1;
			}
		}
		if (!flag) printf("0\n");
	}
	return 0;
}