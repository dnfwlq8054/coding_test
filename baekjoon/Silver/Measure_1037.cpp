#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int MAX = 0;
    int MIN = 9999999;
    int N, K;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> K;
        MAX = max(MAX, K);
        MIN = min(MIN, K);
    }
    
    cout << MAX * MIN << endl;
    
    return 0;
}