#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool flag = false;
    s[0] = toupper(s[0]);
    for(size_t i = 1; i < s.size(); i++){
        if(flag && s[i] != ' '){ s[i] = toupper(s[i]); flag = false; continue; }
        if(s[i] >= '0' && s[i] <= '9') continue;
        else if(s[i] == ' ') flag = true;
        else s[i] = tolower(s[i]);
    }
    return s;
}