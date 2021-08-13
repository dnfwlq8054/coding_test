#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long num = 0;
    for(int i = 0; i < count; i++){
        num += price;
        answer += num;
    }
    
    return answer - money > 0 ? answer - money : 0;
}