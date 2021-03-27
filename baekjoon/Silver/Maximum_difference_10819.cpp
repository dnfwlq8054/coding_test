#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;


int main() {
    int N, K;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int answer = 0;
    do {
        int sum = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            sum += abs(v[i] - v[i + 1]);
        }
        answer = max(answer, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << answer << endl;
    return 0;
}