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

int str_append(string& s1, string& s2, int len) {
    string temp = "";

    for (int i = 0; i < len; i++) {
        temp += s2[i];
    }
    
    temp += s1;
    for (int i = s1.size() + len; i < s2.size(); i++) {
        temp += s2[i];
    }

    int cnt = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (temp[i] != s2[i]) {
            cnt++;
        }
    }

    return cnt;
}

int main(){

    int answer = 999999;
    string s1, s2;
    cin >> s1 >> s2;

    int len = s2.size() - s1.size();
    for (int i = 0; i <= len; i++) {
        answer = min(answer, str_append(s1, s2, i));
    }

    cout << answer << endl;

    return 0;
}