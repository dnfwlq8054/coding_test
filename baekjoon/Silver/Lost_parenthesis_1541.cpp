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
    stack<int> st;
    vector<int> v;
    getline(cin, s);

    int index = 0;
    for (int i = s.size() - 1; i > -1; i--) {
        index++;
        if (s[i] == '-') {
            st.push(-1 * stoi(s.substr(i + 1, index)));
            index = 0;
        }
        else if (s[i] == '+') {
            st.push(stoi(s.substr(i + 1, index)));
            index = 0;
        }else if(i == 0) {
            st.push(stoi(s.substr(i, index)));
            index = 0;
        }
    }
    v.emplace_back(st.top());
    st.pop();

    while (!st.empty()) {
        if (st.top() > 0) {
            if (v.back() > 0) {
                v.back() = v.back() + st.top();
                st.pop();
            }
            else {
                v.back() = -1 * ((-1 * v.back()) + st.top());
                st.pop();
            }
        }
        else {
            v.emplace_back(st.top());
            st.pop();
        }
    }

    int sum = 0;
    for (auto n : v)
        sum += n;

    cout << sum << endl;
    return 0;
}
