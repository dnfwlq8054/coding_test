#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

bool visit[51];

int dfs(string& S, int idx) {
    int cnt = 0;
    for (int i = idx; i < S.size(); i++) {
        if (S[i] == '(' && !visit[i]) {
            visit[i] = true;
            int num = S[i - 1] - '0';
            cnt--;
            cnt += num * dfs(S, i + 1);
        }
        else if (S[i] == ')' && !visit[i]) {
            visit[i] = true;
            return cnt;
        }
        else if(!visit[i]){
            visit[i] = true;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    string answer = "";
    string S;
    
    cin >> S;

    cout << dfs(S, 0) << endl;
    return 0;
}