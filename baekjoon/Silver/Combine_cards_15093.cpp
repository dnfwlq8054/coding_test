#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

int main(void){

    int T, K;
    cin >> T >> K;

    vector<long long> v(T);

    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < K; i++) {
        long long n = v[0] + v[1];
        v[0] = v[1] = n;
        sort(v.begin(), v.end());
    }

    long long sum = 0;
    for (auto n : v)
        sum += n;
    cout << sum << endl;

    return 0;

}

