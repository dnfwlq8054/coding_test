#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int result(int n){
    if(n == 6) return 1;
    else if(n == 5) return 2;
    else if(n == 4) return 3;
    else if(n == 3) return 4;
    else if(n == 2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    map<int, int> m;
    int count = 0;
    int high, low;
    
    for(size_t i = 0; i < lottos.size(); i++)
        m[lottos[i]]++;
    
    for(size_t i = 0; i < win_nums.size(); i++){
        if(m[win_nums[i]] != 0)
            count++;
    }
    
    high = m[0] + count;
    low = count;
    
    answer.emplace_back(result(high));
    answer.emplace_back(result(low));
        
    return answer;
}