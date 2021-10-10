#include <string>
#include <vector>

using namespace std;

bool isflag[101];

int dfs(vector<vector<int>>& graph, vector<bool>& isVisit, int idx){
    int result = 0;
    isVisit[idx] = true;
    
    for(auto& next : graph[idx]){
        if(isflag[idx] && isflag[next]) continue;
        if(!isVisit[next]){
            result += dfs(graph, isVisit, next);
            result++;
        }
    }
    
    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000;
    
    vector<vector<int>> graph(n + 1);
    
    for(auto& v : wires){
        graph[v[0]].emplace_back(v[1]);
        graph[v[1]].emplace_back(v[0]);
    }
    
    for(int idx = 1; idx <= n; idx++){
        for(auto next : graph[idx]){
            vector<bool> isVisit(101);
            isflag[idx] = true; isflag[next] = true;
            
            int result = 1 + dfs(graph, isVisit, idx);
            answer = min(answer, abs(n - (result * 2)));
            
            isflag[idx] = false; isflag[next] = false;
        }
    }
    
    return answer;
}
