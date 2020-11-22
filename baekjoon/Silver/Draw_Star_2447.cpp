#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

void star_init(vector<vector<char>>& v, int x, int y, int h) {
    if (h == 1) {
        v[x][y] = '*';
        return;
    }

    int div = h / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (i == 1 && j == 1) continue;
            star_init(v, x + i * div, y + j * div, div);
        }
    }
}

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    
    cin >> N;
    vector<vector<char>> v(N, vector<char>(N, ' '));

    star_init(v, 0, 0, N);

    for (auto& e : v) {
        for (auto c : e) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}