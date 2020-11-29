#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
bool broken[10];

int check(int a)
{
    if (a == 0) return (broken[a] ? 0 : 1);

    int len = 0;
    while (a)
    {
        if (broken[a % 10]) return 0;
        a /= 10;
        len++;
    }
    return len;
}

int main()
{
    cin >> N >> M;

    int num;
    while (M--)
    {
        cin >> num;
        broken[num] = true;
    }

    int result = abs(N - 100);
    string temp = to_string(N);
    int range = pow(10, temp.size() + 1);
    int len;
    for (int i = 0; i <= range; i++)
    {
        len = check(i);
        if (!len) continue;
        result = min(result, abs(N - i) + len);
    }

    cout << result;

    return 0;
}
