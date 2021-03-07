#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long n1 = 1, n2 = 1, n3 = 0;
    
    for(int i = 2; i <= n; i++){
        n3 = (n1 + n2) % 1000000007;
        n2 = n1;
        n1 = n3;
    }
    return n3;
}