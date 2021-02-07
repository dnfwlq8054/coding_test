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

    vector<int> v;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        string s = "";
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            s += c;
        }
        
        string temp = "";
        temp += s[0];

        for (int j = 1; j < s.size(); j++) {
            if (temp[0] >= s[j])
                temp = s[j] + temp;
            else
                temp += s[j];
        }

        cout << temp << endl;
    }

    return 0;
}
