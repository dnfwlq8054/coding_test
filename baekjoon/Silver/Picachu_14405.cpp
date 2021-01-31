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

int main() {
    
    string s;

    cin >> s;
    int len = s.size();
    
    int i = 0;
    for (; i < len; i++) {
        if (s[i] == 'p') {
            if ("pi" == s.substr(i, 2))
                i++;
            else {
                i = -1;
                break;
            }
        }
        else if (s[i] == 'k') {
            if ("ka" == s.substr(i, 2))
                i++;
            else{
                i = -1;
                break;
            }
        }
        else if (s[i] == 'c') {
            if ("chu" == s.substr(i, 3))
                i += 2;
            else{
                i = -1;
                break;
            }
        }
        else {
            i = -1;
            break;
        }
    }

    if (i != -1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}