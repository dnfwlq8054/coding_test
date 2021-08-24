#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    map<string, int> result;
    map<string, int> pre;
    vector<string> answer;
    int max_score = 0;
    
    for(int i = 0; i < languages.size(); i++)
        pre[languages[i]] = preference[i];
    
    for(auto& s : table){
        int score = 6;
        string word, kind;
        stringstream sstream(s);
        
        while (getline(sstream, word, ' ')){
            if(score == 6) kind = word;
            result[kind] += pre[word] * score--;
        }
        if(max_score < result[kind]) max_score = result[kind];
    }
    
    for(auto itr : result){
        if(max_score == itr.second)
            answer.emplace_back(itr.first);
    }
    
    sort(answer.begin(), answer.end());
    return answer[0];
}