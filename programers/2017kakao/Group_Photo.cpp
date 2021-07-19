#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_char(vector<char>& v, char c){
    for(int i = 0; i < v.size(); i++)
        if(c == v[i]) return i;
    
    return -1;
}

bool func1(vector<char>& v, string& s){
    int a = find_char(v, s[0]);
    int b = find_char(v, s[2]);
    int num = (s[4] - '0') + 1;
    
    if(abs(a - b) == num) return true;
    else return false;
}

bool func2(vector<char>& v, string& s){
    int a = find_char(v, s[0]);
    int b = find_char(v, s[2]);
    int num = (s[4] - '0') + 1;
    
    if(abs(a - b) < num) return true;
    else return false;
}

bool func3(vector<char>& v, string& s){
    int a = find_char(v, s[0]);
    int b = find_char(v, s[2]);
    int num = (s[4] - '0') + 1;
    
    if(abs(a - b) > num) return true;
    else return false;
}

int solution(int n, vector<string> data) {
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int answer = 0;
    
    do {
        bool flag = true;
        for(auto& s : data) {
            if(s[3] == '=') flag = func1(v, s);
            else if(s[3] == '<') flag = func2(v, s);
            else flag = func3(v, s);
            
            if(!flag) break;
        }
        if(flag) answer++;
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}