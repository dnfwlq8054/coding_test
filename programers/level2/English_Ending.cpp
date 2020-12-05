#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    unordered_map<string, int> m;
    char f = words[0].back(), b; m[words[0]] = 1;
    
    for(size_t i = 1; i < words.size(); i++){
        b = words[i][0];
        m[words[i]] += 1;
        
        if(f != b || m[words[i]] == 2){
            answer[0] = i % n + 1; answer[1] = i / n + 1;
            return answer;
        }
        f = words[i].back();
    }

    return answer;
}