#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    int sum = brown + yellow;
    int root = sqrt(brown + yellow);
    
    for (int y = 3; y <= root; y++) {
        if (sum % y == 0) {
            int x = sum / y;
            if ((x - 2) * (y - 2) == yellow) {
                answer[0] = x;
                answer[1] = y;
                break;
            }
        }
    }
    
    return answer;
}