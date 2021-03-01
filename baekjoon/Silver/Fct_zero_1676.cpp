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
    int N, two = 0, five = 0;

    cin >> N;

    for (int i = 2; i <= N; i *= 2)
        two += N / i;

    for (int i = 5; i <= N; i *= 5)
        five += N / i;

    cout << min(two, five) << endl;

    return 0;
}