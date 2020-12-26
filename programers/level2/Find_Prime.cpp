#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iostream>
using namespace std;
 
vector <int> v;
bool allUsed(int i, string numbers);
 
int solution(string numbers) {
    int answer = 0;
    int max = 0;
    
    // numbers 각 자리 수를 v에 넣기
    for (int i = 0; i < numbers.size(); i++) {
        v.push_back(stoi(numbers.substr(i, 1)));
    }
    
    // numbers 숫자를 내림차순으로 정렬
    sort(v.begin(), v.end(), greater<int>());
    
    // max 구하기
    for (int i = 0; i < v.size(); i++) {
        max = max + (v[i] * pow(10, v.size() - 1 - i));
    }
    cout << max << endl;
    vector <bool> isPrime(max+1, true);
    
    // 완전 탐색
    for (int i = 2; i <= max; i++) {
        if (isPrime[i]) {
            // i가 numbers로 나타내어지는 숫자면 answer++ 
            if (allUsed(i, numbers)) {
                answer++;
            }
            
            // 소수 아닌 것들 false로
            for (int j = 2; i * j <= max; j++) {
                isPrime[i * j] = false;
            }
        }
    }
    
    return answer;
}
 
bool allUsed(int i, string numbers) {
    string si = to_string(i);
    vector<bool> visit(v.size(), false);
        
    for (int j = 0; j < si.size(); j++) {
        int index = numbers.find(si.substr(j, 1));
        
        // numbers에서 해당 숫자가 발견되지 않을 경우
        if (index >= numbers.size()) {
            return false;
        }
        else {
            numbers = numbers.substr(0, index) + numbers.substr(index + 1);
        }
    }
    
    return true;
}