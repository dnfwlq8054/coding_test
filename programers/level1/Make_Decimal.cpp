#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool decimal[4000];
int answer = 0;

void dfs(vector<int>& nums, int idx, int deep, int sum){
    if(deep == 3){
        if(!decimal[sum]){
            answer++;
            return;
        }
    }
    
    for(int i = idx; i < nums.size(); i++){
        dfs(nums, i + 1, deep + 1, sum + nums[i]);
    }
}

int solution(vector<int> nums) {
    sort(nums.begin(), nums.end());
    
    for(int i = 2; i < 4000; i++){
        for(int j = i + i; j < 4000; j = j + i){
            decimal[j] = true;
        }
    }
    
    dfs(nums, 0, 0, 0);
        
    return answer;
}