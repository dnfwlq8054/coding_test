#include <iostream>
#include <map>

using namespace std;

int main(){
    
    int N, M;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        
        cin >> M;
        
        map<string, int> m;
        string s1, s2;
        int answer = 1;
        
        for(int j = 0; j < M; j++){
            cin>> s1 >> s2;
            m[s2]++;
        }
        
        for(auto itr = m.begin(); itr != m.end(); itr++)
            answer *= itr->second + 1;
        
        cout << answer -1 << endl;
        
    }
    
    
    return 0;
}