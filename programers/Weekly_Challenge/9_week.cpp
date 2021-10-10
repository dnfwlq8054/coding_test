#include <string>
#include <vector>

using namespace std;

bool isflag[101];

int dfs(vector<vector<int>>& graph, vector<bool>& isVisit, int idx){
    int result = 0;
    
    for(auto& n : graph[idx]){
        if(isflag[idx] && isflag[n]) continue;
        if(!isVisit[n]){
            isVisit[n] = true;
            result += dfs(graph, isVisit, n);
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
    
    for(int i = 0; i < n; i++){
        for(auto next : graph[i + 1]){
            vector<bool> isVisit(101);
            isflag[i + 1] = true; isflag[next] = true;
            isVisit[i + 1] = true;
            
            int result = 1 + dfs(graph, isVisit, i + 1);
            answer = min(answer, abs(n - (result * 2)));
            
            isflag[i + 1] = false; isflag[next] = false;
        }
    }
    
    return answer;
}
