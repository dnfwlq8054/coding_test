#include <iostream>
#include <string>

using namespace std;

int answer_max = 0;
int answer_min = 9999999;

int get_oddCount(int n){
    int cnt = 0;
    while(n > 0){
        int ram = n % 10;
        if(ram % 2 == 1) cnt++;
        
        n /= 10;
    }
    
    return cnt;
}

void dfs(int N, int cnt){
    if(N < 10){
        answer_max = max(answer_max, cnt);
        answer_min = min(answer_min, cnt);
        return;
    }
    
    if(N < 100){
        int x = (N / 10) + (N % 10);
        dfs(x, get_oddCount(x) + cnt);
        return;
    }
    
    string s = to_string(N);
    
    for(int i = 0; i < s.size() - 2; i++){
        for(int j = i + 1; j < s.size() - 1; j++){
            string s1 = s.substr(0, i + 1);
            string s2 = s.substr(i + 1, j - i);
            string s3 = s.substr(j + 1, s.size());
            
            int num = stoi(s1) + stoi(s2) + stoi(s3);
            dfs(num, get_oddCount(num) + cnt);
        }
    }
}

int main(){
    int N;
    cin >> N;
    
    dfs(N, get_oddCount(N));
    
    cout << answer_min << " " << answer_max << endl;
    
    return 0;
    
}