#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int answer = 1, n, T;
    vector<int> v;
    scanf("%d", &T);

    scanf("%d", &n);
    v.emplace_back(n);

    for (int i = 1; i < T; i++) {
        scanf("%d", &n);

        if (n > v.back()) {
            v.emplace_back(n);
            answer++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), n);
            *it = n;
        }
    }

    cout << answer << endl;

    return 0;
}