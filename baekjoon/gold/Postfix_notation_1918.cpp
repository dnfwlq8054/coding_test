#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

int main() {

    string s;
    cin >> s;

    stack<char> st;

    string answer = "";

    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && 'Z' >= s[i])
            answer += s[i];
        else {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == '*' || s[i] == '/') {
                while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    answer += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-') {
                while (!st.empty() && st.top() != '(') {
                    answer += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    answer += st.top();
                    st.pop();
                }
                st.pop();
            }
        }
    }
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }

    cout << answer << endl;
    return 0;
}