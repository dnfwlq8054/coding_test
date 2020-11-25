#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    string S;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        int cnt = 0;
        
        for (auto& c : S) {
            if (c == '(')
                cnt++;
            else
                cnt--;

            if (cnt < 0) {
                break;
            }
        }
        if (cnt == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}