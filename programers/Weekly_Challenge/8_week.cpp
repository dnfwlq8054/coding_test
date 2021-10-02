#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_horizontal = 0;
    int max_vertical = 0;
    
    for(auto& v : sizes){
        for(auto n : v){
            max_horizontal = max(max_horizontal, n);
        }
        sort(v.begin(), v.end());
    }
    
    for(auto& v : sizes){
        if(max_vertical < v[0]) max_vertical = v[0];
    }
    
    return max_vertical * max_horizontal;
}