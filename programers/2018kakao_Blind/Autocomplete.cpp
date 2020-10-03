#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Trie {
private:
    Trie * child[26]{};
    int count[26]{};
    
public:
    
    void insert(const char * c){
        if(*c == '\0') return;
        
        int next = *c - 'a';
        count[next]++;
        
        if(child[next] == 0){
            child[next] = new Trie();
            child[next]->insert(c + 1);
        }else
            child[next]->insert(c + 1);  
    }
    
    int find(const char * c, int num){
        if(*c == '\0') return num - 1;
        
        int next = *c - 'a';
        
        if(count[next] == 1) return num;
        
        return child[next]->find(c + 1, num + 1);      
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie t;
    for(int i = 0; i < words.size(); i++)
        t.insert(words[i].c_str());
    for(int i = 0; i < words.size(); i++)
        answer += t.find(words[i].c_str(), 1);
    
    return answer;
}