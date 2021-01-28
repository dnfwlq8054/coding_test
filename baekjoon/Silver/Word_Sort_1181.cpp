#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

struct cmp {
    bool operator() (const string& s1, const string& s2) const {
        if (s1.size() == s2.size())
            return s1 < s2;
        else 
            return s1.size() < s2.size();
    }
};

int main() {
    
    int N, M, answer = 0;
    int x, y, cost;
    cin >> N;

    set<string, cmp> dic;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        dic.emplace(s);
    }

    for (auto& t : dic)
        cout << t << endl;

    return 0;
}