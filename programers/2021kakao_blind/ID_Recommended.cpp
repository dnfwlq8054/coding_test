#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    
    for(int i = 0; i < s.size(); i++)
        if((s[i] >= 'a' && s[i] <= 'z') || s[i] == '-' || s[i] == '_' || s[i] == '.'
          || (s[i] >= '0' && s[i] <= '9'))
            answer += s[i];
    
    temp += answer[0];
    for(int i = 1; i < answer.size(); i++){
        if(temp.back() == '.' && answer[i] == '.')
            continue;
        temp += answer[i];
    }
        
    if(temp.back() == '.') temp.pop_back();
    if(temp[0] == '.') temp.erase(temp.begin());
    
    if(temp.size() == 0) temp = "aaa";
    
    answer = temp.substr(0, 15);
    if(answer.back() == '.') answer.pop_back();
    
    if(answer.size() <= 2){
        while(answer.size() <= 2)
            answer += answer.back();
    }
    return answer;
}