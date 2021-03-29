#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int costs[501];
int indegree[501];
 
int main(){
 
    int N, K;
    cin >> N;
    vector<vector<int>> v(N);
    vector<int> dp (N);
 
    for(int i = 0; i < N; i++){
        cin >> costs[i];
        dp[i] = costs[i];
        cin >> K;
 
        while(K != -1){
            v[K - 1].emplace_back(i);
            indegree[i]++;
            cin >> K;
        }
    }
 
    queue<int> q;
    for(int i = 0; i < N; i++)
        if(indegree[i] == 0)
            q.emplace(i);

    while(!q.empty()){
        int n = q.front();
        q.pop();
		
        for(int i = 0; i < v[n].size(); i++){
            dp[v[n][i]] = max(dp[v[n][i]], dp[n] + costs[v[n][i]]);
 
            if(--indegree[v[n][i]] == 0){
                q.emplace(v[n][i]);
            }
        }
    }
 
    for(int i = 0; i < N; i++){
    	cout << dp[i] << endl;
    }
    return 0;
}