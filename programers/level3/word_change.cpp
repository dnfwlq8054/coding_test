#include <string>
#include <vector>

using namespace std;

int answer = 100;
string tar;
bool check[51];

void dfs(string begin, vector<string>& words, int result){
    
    if(tar == begin) {
        answer = min(answer, result);
        return;
    }
    
    for(size_t i = 0; i < words.size(); i++){
        int count = 0;
        for(size_t j = 0; j < words[i].size(); j++){
            if(begin[j] != words[i][j]) count++;
            if(count == 2) break;
        }
        if(count == 1){
            if(check[i] == false){
                check[i] = true;
                dfs(words[i], words, result + 1);
                check[i] = false;
            }
        }    
    }
}

int solution(string begin, string target, vector<string> words) {
    tar = target;
    dfs(begin, words, 0);
    if(answer == 100) answer = 0;
    return answer;
}