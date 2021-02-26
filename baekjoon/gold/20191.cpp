#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>

#pragma warning(disable: 4996)

#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

string s, t;

vector<int> alpha[26];
int ans = 1, ps, pt, tl, sl;
int main() {

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> s >> t;
    sl = s.size();
    tl = t.size();
    rep(i, tl) {
        alpha[t[i] - 'a'].emplace_back(i);
    }
    while (ps < sl) {
        int x = s[ps] - 'a';
        if (alpha[x].empty()) {
            cout << -1;
            exit(0);
        }

        int pos = lower_bound(alpha[x].begin(), alpha[x].end(), pt) - alpha[x].begin();
        if (pos >= alpha[x].size()) {
            ans += 1;
            pos = 0;
        }
        pt = alpha[x][pos];
        pt += 1;
        ps += 1;
    }
    cout << ans;
    return 0;
}