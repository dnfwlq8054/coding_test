#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;
unordered_map<string, pair<double, double>> link_score;
unordered_map<string, vector<string>> a_hrefList;

int find_string(const char * word, const string&s, int index){
    if(*word == '\0'){
        if((s[index] < 'A' || s[index] > 'Z') && (s[index] < 'a' || s[index] > 'z') ){
            return index;
        } return 0;
    }
    
    if(*word == tolower(s[index]))
        return find_string(word + 1, s, index + 1);
    
    else
        return 0;
}

int find_meta(const string& s){
    for(int i = 0; i < s.size(); i++){
        int flag = 0;
        if(s[i] == '<'){
            if((flag = find_string("<meta property=\"og:url\" content=\"https:/", s, i))){
                return flag;
            }
        }
    }
    return 0;
}
string content_init(const string&s, int& index){
    string temp = ""; index++;
    for(; index < s.size(); index++){
        if(s[index] == '\"')
            return temp;
        else
            temp += s[index];
    }
    return "";
}
int body_line(const string& body, const string& s, int index){
    for(int i = index; i < s.size(); i++){
        int flag = 0;
        if(body[0] == s[i]){
            if((flag = find_string(body.c_str(), s, i))){
                return flag;
            }
        }
    }
    return 0;
}

void link_n_word(const string& word, const string& s, int index, const string& my_link, const int& n){
    int link_point = 0, word_point = 0, j = 0;
    
    for(int i = index; i < s.size(); i++){
        int flag = 0;
        if(word[0] == tolower(s[i])){
            if((s[i - 1] < 'A' || s[i - 1] > 'Z') && (s[i - 1] < 'a' || s[i - 1] > 'z' )){
                if((flag = find_string(word.c_str(), s, i))){
                    word_point++; i = flag;
                }
            }
        }else if('<' == s[i]){
            if((flag = find_string("<a href=\"https:/", s, i))){
                string link_cp = "";
                i = flag + 1;
                while(s[i] != '\"'){ link_cp += s[i]; i++;}
                link_point++;
                a_hrefList[my_link].emplace_back(link_cp);
            }
        }
    }
    
    link_score[my_link].first = (double)word_point;
    link_score[my_link].second = (double)word_point / (double)link_point;
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    vector<string> webList;
    for(int i = 0; i < word.size(); i++)
        word[i] = tolower(word[i]);
    
    for(int i = 0; i < pages.size(); i++){
        int meta = find_meta(pages[i]);
        string my_link = content_init(pages[i], meta);
        webList.emplace_back(my_link);
        int index = body_line("<body>", pages[i], meta);
        link_n_word(word, pages[i], index, my_link, i);
    }
    
    for(int i = 0; i < webList.size(); i++){
        for(int j = 0; j < a_hrefList[webList[i]].size(); j++){
            string s = a_hrefList[webList[i]][j];
            link_score[s].first += link_score[webList[i]].second;
        }
    }
    
    double score_max = link_score[webList[0]].first;
    for(int i = 1; i < webList.size(); i++){
        if(score_max < link_score[webList[i]].first){
            score_max = link_score[webList[i]].first;
            answer = i;
        }
    }
    return answer;
}