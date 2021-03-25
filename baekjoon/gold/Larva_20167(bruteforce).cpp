#include <iostream>
#include <vector>
#include <algorithm>

int ans = 0;
int N, K;

using namespace std;

void dfs(vector<int>& v, int idx, int result){
    
    if(idx >= N){
        ans = max(ans, result);
        return;
    }
    
    int sum = 0;
    
    for(int i = idx; i < N; i++){
        sum += v[i];
        if(sum >= K){
            dfs(v, i + 1, result + sum - K);
            break;
        }
    }
    
    dfs(v, idx + 1, result);
}

int main(){
    cin >> N >> K;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    
    dfs(v, 0, 0);
    cout << ans << endl;
}