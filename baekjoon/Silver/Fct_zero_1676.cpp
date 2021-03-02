#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>
#include <cmath>

#pragma warning(disable: 4996)

using namespace std;

int main(){
    int N, five = 0;

    cin >> N;

    for (int i = 5; i <= N; i *= 5)
        five += N / i;

    cout << five << endl;

    return 0;
}