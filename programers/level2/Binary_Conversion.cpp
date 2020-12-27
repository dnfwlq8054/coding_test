#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0;
    int cycle = 0;
    
    while(s.size() != 1){
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') zero_count++;
            else temp += s[i];
        }
        
        int temp_len = temp.size();
        s = "";
        while(temp_len != 0){
            s += to_string(temp_len % 2);
            temp_len /= 2;
        }
        
        cycle++;
    }
    answer.emplace_back(cycle);
    answer.emplace_back(zero_count);
    return answer;
}