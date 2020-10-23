#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N; cin >> M;
	int MAX = 0;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if(MAX < A[i]) MAX = A[i];
	}

	long long start = 1, end = MAX;
	int answer = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		int count = 0;
        
		for (auto num : A) {
			count += num / mid;
		}
        
		if (count < M){
			end = mid - 1;
		}
		else {
			if(answer < mid) answer = mid;
			start = mid + 1;
		}
	}
	cout << answer << endl;
	return 0;
}