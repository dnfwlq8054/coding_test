#include <string>
#include <vector>
#include <map>
 
using namespace std;
 
bool check(const char * m, const string& song, int i){
    if(*m == '\0') return true; 
    if(*m == song[i]) 
        return check(m + 1, song, i + 1);
    else return false;
}
 
bool find_song(const string& m, const string& song){
    for(int i = 0; i < song.size() - m.size(); i++){
        if(m[0] == song[i]){
            if(check(m.c_str(), song, i))
                return true;
        }
    }
    return false;
}
 
string append_song(const string& s, int index, int len){
    string temp = "";
    int j = index;
    while(temp.size() < len){
        if(j == s.size()){ j = index; continue; }
        if(s[j] == '#') temp.back() = temp.back() + 32;
        else temp += s[j];
        j++;
    }
    if(s[j] == '#') temp.back() = temp.back() + 32;
    return temp += '.';
}
 
string find_head(const string& s, int& i){
    string temp = "";
    for(; i < s.size(); i++ ){
        if(s[i] == ',')
            break;
        temp += s[i];
    }
    i++;
    return temp;
}
 
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    map<int, vector<string>, greater<int>> result;
    string cp_m = "";
 
    for(int i = 0; i < m.size(); i++){
        if(m[i] == '#') cp_m.back() = cp_m.back() + 32;
        else cp_m += m[i];
    }
 
    for(int i = 0; i < musicinfos.size(); i++){
        int h = (musicinfos[i][6] - '0') - (musicinfos[i][0] - '0');
        h = (h * 10) + (musicinfos[i][7] - '0') - (musicinfos[i][1] - '0');     
        int mm = (musicinfos[i][9] - '0') - (musicinfos[i][3] - '0');
        mm = (mm * 10) + (musicinfos[i][10] - '0') - (musicinfos[i][4] - '0');
        int len = (h * 60) + mm;
        int index = 12;
 
        string title = find_head(musicinfos[i], index);
        string song = append_song(musicinfos[i], index, len);
 
        if(song.size() - 1 < cp_m.size()) continue;
        if(find_song(cp_m, song)) { result[len].emplace_back(title); }
    }
 
    map<int, vector<string>, greater<int>>::iterator itr = result.begin();
 
    if(result.size() == 0)
        return answer;
    else
        return itr->second[0];
}
