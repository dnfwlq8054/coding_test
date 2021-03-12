#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int answer = 0;
    string s;
    
    cin >> s;
    
    for(int idx = 0; idx < s.size() - 4; idx++){
        string temp = s.substr(idx, s.size());
        vector<int> table(temp.size());
        int j = 0;
        
        for(int i = 1; i < temp.size(); i++){
            while(j > 0 && temp[i] != temp[j])
                j = table[j - 1];
            
            if(temp[i] == temp[j]){
                table[i] = ++j;
                if(j > 1)
                    answer = max(answer, j);
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}