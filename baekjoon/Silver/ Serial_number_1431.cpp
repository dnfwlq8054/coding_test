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

int number_count(string& s) {
    int sum = 0;
    for (auto c : s) {
        if ('0' <= c && c <= '9') {
            int num = c - '0';
            sum += num;
        }
    }
    return sum;
}

int main(void){

    int T;
    cin >> T;

    vector<string> v(T);
    for (int i = 0; i < T; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        if (a.size() == b.size()) {
            int s1_len = number_count(a);
            int s2_len = number_count(b);

            if (s1_len == s2_len) {
                return a < b;
            }
            else {
                if (s1_len > s2_len) return false;
                else return true;
            }
        }
        else
            return a.size() < b.size();
    });
    
    for (auto& s : v)
        cout << s << endl;

    return 0;

}

