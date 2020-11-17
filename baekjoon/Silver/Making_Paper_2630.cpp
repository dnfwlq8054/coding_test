#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int zero = 0;
int one = 0;

int divide(vector<vector<int>>& v, int x, int y, int h) {
    if (h == 1) {
        if (v[x][y] == 1) one++;
        else zero++;
        return v[x][y];
    }
    int num = 0;
    num += divide(v, x, y, h / 2);
    num += divide(v, x + (h / 2), y, h / 2);
    num += divide(v, x, y + (h / 2), h / 2);
    num += divide(v, x + (h / 2), y + (h / 2), h / 2);

    if (num == 4) {
        one -= 3;
        return 1;
    }

    if (num == 0) {
        zero -= 3;
        return 0;
    }

    return -100;
}

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &v[i][j]);

    divide(v, 0, 0, N);

    cout << zero << endl;
    cout << one << endl;
    return 0;
}