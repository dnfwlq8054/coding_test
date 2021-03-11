#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(const string& pattern){
    vector<int> table(pattern.size());
    int j = 0;
    
    for(int i = 1; i < pattern.size(); i++){
        while(j > 0 && pattern[i] != pattern[j])
            j = table[j - 1];
        
        if(pattern[i] == pattern[j])
            table[i] = ++j;
    }
    
    return table;
}

int KMP(const string& s, const string& pattern){
    vector<int> table = makeTable(pattern);
    int j = 0;
    
    for(int i = 0; i < s.size(); i++){
        while(j > 0 && s[i] != pattern[j])
            j = table[j - 1];
        
        if(s[i] == pattern[j]){
            if(j == pattern.size() - 1)
                return 1;
            else
                j++;
        }
    }
    
    return 0;
}

int main(){
    
    string s, pattern;
    cin >> s >> pattern;
    
    cout << KMP(s, pattern) << endl;
    
    return 0;
}