#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#pragma warning(disable: 4996)

using namespace std;

int main() {

    int N, answer = 0;
    cin >> N;
    string s;
    vector<string> v;
    
    for (int i = 0; i < N; i++) {
        cin >> s;
        v.emplace_back(s);
    }

    vector<int> arpabat(26);

    for (auto& temp : v) {
        int cnt = 1;
        for_each(temp.rbegin(), temp.rend(), [&](auto c) {
            int n = c - 'A';
            arpabat[n] += cnt;
            cnt *= 10;
            });
    }

    sort(arpabat.rbegin(), arpabat.rend());

    int count = 9;
    for (auto n : arpabat) {
        answer += (n * count--);
    }

    cout << answer << endl;

    return 0;
}