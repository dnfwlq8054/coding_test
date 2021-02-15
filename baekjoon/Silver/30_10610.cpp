#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <deque>

#pragma warning(disable: 4996)

using namespace std;


int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    string s;
    bool flag = false;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        answer += s[i] - '0';
        if (s[i] == '0') flag = true;
    }

    sort(s.rbegin(), s.rend());
    
    if (answer % 3 == 0 && flag)
        cout << s << endl;
    else
        cout << -1 << endl;
    return 0;
}
