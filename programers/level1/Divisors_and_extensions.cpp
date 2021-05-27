#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        int num = sqrt(i);
        int count = 0;
        for(int j = num; j > 0; j--){
            if(i % j == 0){
                if(j == i / j) count += 1;
                else count += 2;
            }
        }
        
        if(count % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}