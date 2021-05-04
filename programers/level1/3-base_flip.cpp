#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s = "";
    
    while(n != 0){
        int rem = n % 3;
        n /= 3;
        s += to_string(rem);
    }
    string temp(s.rbegin(), s.rend());
    answer = temp[0] - '0';
    
    for(int i = 1, j = 3; i < s.size(); i++, j = j * 3){
        int num = temp[i] - '0';
        answer += num * j;
    }
    return answer;
}