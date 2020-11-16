#include <string>
#include <vector>
#include <stack>

using namespace std;

int index;

bool check(const string& p){
    int left = 0, right = 0;
    bool ret = true;
    stack<char> s;
    
    for(int i = 0; i < p.size(); i++){
        if(p[i] == '('){
            left++;
            s.push('(');
        }else{
            if(s.empty())
                ret = false;
            else
                s.pop();
            
            right++;
        }
        if(left == right){
            index = i + 1;
            return ret;
        }
    }
    return ret;
}

string solution(string p) {
    if(p == "")
        return "";
    
    string u, v;
    bool isCheck = check(p);
    
    u = p.substr(0, index);
    v = p.substr(index);
    
    if(isCheck)
        return u + solution(v);
    
    string answer = "";
    answer += '(';
    answer += solution(v) + ')';
    
    for(int i = 1; i < u.size() - 1; i++){
        if(u[i] == '(')
            answer += ')';
        else
            answer += '(';
    }
    
    return answer;
}