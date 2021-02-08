#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    string s;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        int left = 0;
        int right = s.size() - 1;
        bool flag = true;
        int count = 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
                continue;
            }

            if (s[left] != s[right] && count == 1) {

                if (s[left + 1] == s[right]) {
                    left++;
                    count--;
                }
                
                if (s[left] == s[right - 1]) {
                    right--;
                    count--;
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag && count == 1)
            cout << 0 << endl;
        else if (flag && count == 0)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }

    return 0;
}
