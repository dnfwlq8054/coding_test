#include <iostream>
#include <vector>
#include <queue>
#include <map>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    int cost = 0;
    string s;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        bool flag = false;
        char c = s[0];
        map<int, int> m;
        
        for (int j = 1; j < s.size(); j++) {
            if (c != s[j])
                m[c]++;

            if (m[c] == 2){
                flag = true;
                break;
            }
            c = s[j];
        }
        m[c]++;
        if (m[c] == 2) continue;
        if (!flag) answer++;
    }
  
    cout << answer << endl;
    return 0;
}