#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    long long as = 0;
    map<int, int> indegree;
    map<int, long long> weight;
    vector<vector<int>> v(a.size());
    vector<bool> isVisit(a.size());
    
    for(int i = 0; i < a.size(); i++){
        weight[i] = a[i];
        answer += a[i];
        as += abs(a[i]) - 1;
    }
    
    if(answer != 0) return -1;
    else answer = 0;
    
    for(int i = 0; i < edges.size(); i++){
        int x = edges[i][0];
        int y = edges[i][1];
        v[x].emplace_back(y);
        v[y].emplace_back(x);
        indegree[x]++;
        indegree[y]++;
    }
    
    queue<int> q;
    for(auto itr = indegree.begin(); itr != indegree.end(); itr++){
        if(itr->second == 1){
            q.emplace(itr->first);
            indegree[itr->first]--;
        }
    }
    
    while(!q.empty()){
        int n = q.front();
        q.pop();
        isVisit[n] = true;
        
        for(int i = 0; i < v[n].size(); i++){
            if(!isVisit[v[n][i]]){
                weight[v[n][i]] += weight[n];
                answer += abs(weight[n]);
                weight[n] = 0;
                
                if(--indegree[v[n][i]] == 1){
                    q.emplace(v[n][i]);
                }
            }
        }
    }
    
    return answer;
}
