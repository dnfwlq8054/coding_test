#include <string>
#include <vector>
#include <stack>

using namespace std;

bool counting(string& s, int cnt, int len){
    stack<char> st;
    int count = 0;
    
    for(int i = 0; i < s.size(); i++){
        char c = s[(i + cnt) % len];
        
        if(c == '(' || c == '[' || c == '{')
            st.push(c);
        else{
            if(st.empty()) return false;
            
            char pop_c = st.top();
            st.pop();

            if(c == ')' && pop_c == '(') continue;
            else if(c == ']' && pop_c == '[') continue;
            else if(c == '}' && pop_c == '{') continue;
            else return false;;
        }
    }
    if(!st.empty()) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    int count = 0;
    int len = s.size();
    
    if(s.size() == 1)
        return 0;
    
    for(int i = 0; i < s.size(); i++){
        if(counting(s, count++, len))
            answer++;
    }
    return answer;
}