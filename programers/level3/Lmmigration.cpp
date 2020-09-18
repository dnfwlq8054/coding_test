#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long int Max = *max_element(times.begin(), times.end()) * static_cast<long long>(n);
    long long answer = Max;
    long long Min = 1, Mid = 0;
    
    while(Min <= Max){
        Mid = (Min + Max) / 2;
        long long num = n;
        
        for(auto nn : times){
            num -= (Mid / nn);
            if(num < 0) break;
        }
        
        if(num <= 0){
            answer = min(answer, Mid);
            Max = Mid - 1;
        }
        else
            Min = Mid + 1;
        
    }
    return answer;
}