#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int w_count = 0;

class Trie {
private:
    Trie * child[26]{};
    map<int, int> m;
    bool check = false;
public:
    void insert(const char * word, int n, int w_size){
        if(*word == '\0'){ return; }
        int next = *word - 'a';
        m[w_size]++;
        check = true;
        
        if(child[next] == 0){
            child[next] = new Trie();
            child[next]->insert(word + 1, n + 1, w_size - 1);
        }else
            child[next]->insert(word + 1, n + 1, w_size - 1);
        
        return;
    }
    
    void find(const char * word, int word_len){
        if(*word == '\0'){
            if(check == false)
                { w_count++; return; }
            return;
        }

        if(*word == '?'){ w_count = m[word_len]; return; }
        int next = *word - 'a';
        if(child[next] != 0){ child[next]->find(word + 1, word_len - 1); }
        
        return;
    }
    ~Trie(){
        for(int i = 0; i < 26; i++) delete child[i];
        map<int, int>().swap(m);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie, r_trie;
    
    for(int i = 0; i < words.size(); i++){
        trie.insert(words[i].c_str(), 1, words[i].size());
        reverse(words[i].begin(), words[i].end());
        r_trie.insert(words[i].c_str(), 1, words[i].size());
    }
    
    for(int i = 0; i < queries.size(); i++){
        if(queries[i][0] == '?'){
            reverse(queries[i].begin(), queries[i].end());
            r_trie.find(queries[i].c_str(), queries[i].size());
        }
        else
            trie.find(queries[i].c_str(), queries[i].size());
        
        if(w_count == 0) answer.emplace_back(0);
        else{ answer.emplace_back(w_count); w_count = 0; }        
    }
    
    return answer;
}