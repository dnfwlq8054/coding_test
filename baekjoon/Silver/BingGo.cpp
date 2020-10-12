#include <iostream>
#include <vector>

using namespace std;

bool bingGo_x[5];
bool bingGo_y[5];
bool bingGo_cross[2];
bool check[5][5];

bool bingGo_checkX(int x) {
    for (int i = 0; i < 5; i++) {
        if (!check[x][i])
            return false;
    }
    return true;
}

bool bingGo_checkY(int y) {
    for (int i = 0; i < 5; i++) {
        if (!check[i][y])
            return false;
    }
    return true;
}

bool cross_check(int x, int y) {
    if (x == y && !bingGo_cross[0]) {
        for (int i = 0; i < 5; i++) {
            if (!check[i][i])
                return false;
        }
        bingGo_cross[0] = true;
        return true;
    }
    else if (x + y == 4 && !bingGo_cross[1]) {
        for (int i = 0; i < 5; i++) {
            if (!check[4 - i][i])
                return false;
        }
        bingGo_cross[1] = true;
        return true;
    }
    else
        return false;
}

int main()
{
    int count = 0;
    vector<int> v(25), b(25);
    for (int i = 0; i < 25; i++)
        cin >> v[i];

    for (int i = 0; i < 25; i++)
        cin >> b[i];

    for (int i = 0; i < 25; i++) {
        int N = b[i];
        int x, y;

        for (int j = 0; j < 25; j++) {
            if (v[j] == N) {
                x = j / 5;
                y = j % 5;
                break;
            }
        }

        check[x][y] = true;

        if (!bingGo_x[x]) {
            if (bingGo_checkX(x)) {
                bingGo_x[x] = true;
                count++;
            }
        }
        if (!bingGo_y[y]) {
            if (bingGo_checkY(y)) {
                bingGo_y[y] = true;
                count++;
            }
        }
        if (x == 2 && y == 2) {
            if (cross_check(0, 0)) {
                count++;
            }
            if (cross_check(0, 4)) {
                count++;
            }
        }
        else if (x == y || x + y == 4) {
            if (cross_check(x, y)) {
                count++;
            }
        }

        if (count > 2) {
            cout << i + 1 << endl;
            break;
        }
    }


    return 0;
}
