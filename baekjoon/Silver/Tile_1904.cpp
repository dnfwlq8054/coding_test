#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int n1 = 1;
    int n2 = 0;
    int sum;

    for(int i = 0; i < N; i++){
        sum = (n1 + n2) % 15746;
        n2 = n1;
        n1 = sum;
    }

    cout << sum << endl;
    return 0;
}